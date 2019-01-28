/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:03 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 18:19:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAP_SIZE 256

static void	fill_map(char *map)
{
	ft_bzero(map, MAP_SIZE);
	map['#'] = FLAG_PREPOUND;
	map['0'] = FLAG_ZERO;
	map['+'] = FLAG_PLUS;
	map['-'] = FLAG_MINUS;
	map[' '] = FLAG_SPACE;
}

int			parse_flags(t_formatinfo *info,
						const char *restrict format,
						int *pos)
{
	t_bool	any;
	char	map[MAP_SIZE];
	char	flag;
	char	c;

	fill_map(map);
	any = false;
	while (format[*pos] != '\0')
	{
		c = format[*pos];
		flag = map[(int)c];
		if (flag != 0)
		{
			info->flags |= flag;
			any = true;
		}
		else
			return (any);
		(*pos)++;
	}
	return (any);
}
