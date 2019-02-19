/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:34:10 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/19 16:21:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function for creating a new bitmap for storing the route
** and calculate the conflict between the routes
*/

t_bitmap	*bitmap_new(size_t bits_size)
{
	t_bitmap	*res;

	res = malloc(sizeof(t_bitmap));
	res->map = ft_memalloc(bits_size / 8 + (((bits_size % 8) > 0) ? 1 : 0));
	res->bits_size = bits_size;
	return (res);
}

/*
** Function to take information in the bitmap
*/

t_bool		bitmap_get(t_bitmap *bitmap, size_t index)
{
	t_bool	res;
	size_t	byte_offset;
	char	bit_offset;

	byte_offset = index / 8;
	bit_offset = index % 8;
	res = bitmap->map[byte_offset] & (0x01 << bit_offset);
	return (res);
}

/*
** Function for add informtion in  the bitmap
*/

void		bitmap_set(t_bitmap *bitmap, size_t index)
{
	size_t	byte_offset;
	char	bit_offset;

	byte_offset = index / 8;
	bit_offset = index % 8;
	bitmap->map[byte_offset] |= (0x01 << bit_offset);
}

/*
**	Duplicates the bitmap and its sub elements.
*/

t_bitmap	*bitmap_copy(t_bitmap *bitmap)
{
	t_bitmap	*res;
	int			bits_size;

	bits_size = bitmap->bits_size;
	res = bitmap_new(bits_size);
	ft_memcpy(res->map, bitmap->map, bits_size / 8 + (((bits_size % 8) > 0) ? 1 : 0));
	return (res);
}

/*
**	Free bitmap's elements.
*/

void		bitmap_free(t_bitmap *bitmap)
{
	free(bitmap->map);
	free(bitmap);
}

void	bitmap_print(t_bitmap *bitmap)
{
	int		val;
	size_t	i;

	i = 0;
	while (i < bitmap->bits_size)
	{
		val = bitmap_get(bitmap, i);
		if (val)
			ft_putchar('1');
		else
			ft_putchar('0');
		i++;
	}
	ft_putendl("");
}
