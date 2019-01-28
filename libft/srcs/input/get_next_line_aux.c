/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:21:24 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:14:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl_error(const int fd, char **line, t_list **lst)
{
	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0 || BUFF_SIZE < 1)
	{
		ft_lst_del(lst);
		return (-1);
	}
	if (*line != NULL)
		ft_strdel(line);
	return (1);
}

int		gnl_lst(const int fd, t_list **tmp, char **str, t_list **lst)
{
	*str = NULL;
	if (*tmp && (*tmp)->content != NULL && ft_strlen((*tmp)->content) != 0)
	{
		*str = ft_strdup((*tmp)->content);
		*lst = ft_lst_del_one(*lst, (*tmp)->content, fd);
	}
	return (1);
}
