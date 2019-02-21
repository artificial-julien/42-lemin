/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:43:20 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/20 10:59:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print the bitmap.
*/

void		bitmap_print(t_bitmap *bitmap)
{
	int		val;
	size_t	i;

	i = 0;
	while (i < bitmap->bits_size)
	{
		val = bitmap_get(bitmap, i);
		if (val)
			ft_putchar_fd('1', 2);
		else
			ft_putchar_fd('0', 2);
		i++;
	}
	ft_putendl_fd("", 2);
}

/*
**	Duplicates the bitmap and its sub elements.
*/

t_bitmap	*bitmap_copy(t_bitmap *bitmap)
{
	t_bitmap	*res;
	int			bits_size;
	int			bits_test;

	bits_size = bitmap->bits_size;
	res = bitmap_new(bits_size);
	bits_test = bits_size / 8 + (((bits_size % 8) > 0) ? 1 : 0);
	ft_memcpy(res->map, bitmap->map, bits_test);
	return (res);
}

/*
**	Resets all bitmap values to 0.
*/

void		bitmap_reset(t_bitmap *bitmap)
{
	size_t	bits_size;
	size_t	size;
	size_t	i;

	bits_size = bitmap->bits_size;
	size = bits_size / 8 + (((bits_size % 8) > 0) ? 1 : 0);
	i = 0;
	while (i < size)
	{
		bitmap->map[i] = 0;
		i++;
	}
}
