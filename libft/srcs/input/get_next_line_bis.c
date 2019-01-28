/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:27:51 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:14:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ret_strlen(char *s)
{
	int pos_ret;

	pos_ret = 0;
	if (s == NULL || s[0] == '\0')
		return (-1);
	while (s[pos_ret])
	{
		if (s[pos_ret] == '\n')
			return (pos_ret);
		pos_ret++;
	}
	return (-1);
}

static t_list	*init_get(t_list **lst, int fd)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp && tmp->content)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (*lst);
}

static int		get_str(int fd, char **line, char *tmp, t_list **lst)
{
	int		ind;
	char	*str;
	int		l;

	l = ft_strlen(tmp);
	str = NULL;
	ind = 0;
	if ((ind = ret_strlen(tmp)) != -1 && l > ind)
	{
		str = ft_strsub(tmp, (ind + 1), (l - (ind + 1)));
		ft_lstadd(lst, ft_lstnewchar(str, ft_strlen(str)));
		(*lst)->content_size = (size_t)fd;
		*line = ft_strsub(tmp, 0, ind);
		free(str);
	}
	else
		*line = ft_strdup(tmp);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int		test_content(const int fd, char **tmp)
{
	char	buf[BUFF_SIZE + 1];
	t_list	*l_buf;
	int		size;
	int		n;

	size = 0;
	l_buf = NULL;
	ft_bzero(buf, BUFF_SIZE);
	while ((ret_strlen(buf) == -1) && (n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		ft_lstadd_last(&l_buf, ft_lstnewchar(buf, sizeof(char) * n));
		size = size + n;
	}
	if ((*tmp = ft_realloc(*tmp, (size))) == NULL)
		return (-1);
	while (l_buf != NULL && l_buf->content != NULL)
	{
		*tmp = ft_strcat(*tmp, l_buf->content);
		l_buf = ft_lst_del_one(l_buf, l_buf->content, l_buf->content_size);
	}
	return (n);
}

int				get_next_line_bis(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	char			*str;
	int				n;

	if (gnl_error(fd, line, &lst) == -1)
		return (-1);
	n = -1;
	str = NULL;
	tmp = init_get(&lst, fd);
	gnl_lst(fd, &tmp, &str, &lst);
	if (ret_strlen(str) == -1)
	{
		n = test_content(fd, &str);
		if ((n == 0 && str[0] == '\0') || n == -1)
			return (n);
	}
	n = get_str(fd, line, str, &lst);
	free(str);
	if (*line == NULL)
		return (-1);
	return (n);
}
