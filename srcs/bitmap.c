/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:34:10 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/31 19:56:27 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bitmap	*bitmap_new(size_t bits_size)
{
	t_bitmap	*res;

	res = malloc(sizeof(t_bitmap));
	res->map = malloc(bits_size / 8 + (((bits_size % 8) > 0) ? 1 : 0));
	res->bits_size = bits_size;
}

t_bool		bitmap_get(t_bitmap *bitmap, size_t index)
{
	t_bool	res;
	size_t	byte_offset;
	char	bit_offset;

	byte_offset = index / 8;
	bit_offset = index % 8;
	res = bitmap->map[byte_offset] & (0x01 << bit_offset);
}

void		bitmap_set(t_bitmap *bitmap, size_t index)
{
	t_bool	res;
	size_t	byte_offset;
	char	bit_offset;

	byte_offset = index / 8;
	bit_offset = index % 8;
	bitmap->map[byte_offset] |= (0x01 << bit_offset);
}
