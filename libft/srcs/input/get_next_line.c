/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:47:56 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 18:35:06 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

#define BUFF_SIZE 128

static unsigned int	linelen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char			*append(char *s1, char *s2)
{
	char		*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	if (str == NULL)
		return (NULL);
	return (str);
}

static int			shift_to_end(char *str)
{
	char	*lineend;

	lineend = ft_strchr(str, '\n');
	if (lineend)
	{
		ft_strcpy(str, lineend + 1);
		return (1);
	}
	if (linelen(str) > 0)
	{
		*str = '\0';
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	ssize_t		res;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(save[fd]) && (save[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) &&
			(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = append(save[fd], buff);
		if (save[fd] == NULL)
			return (-1);
	}
	*line = ft_strsub(save[fd], 0, linelen(save[fd]));
	if (!shift_to_end(save[fd]))
		return (0);
	return (1);
}
