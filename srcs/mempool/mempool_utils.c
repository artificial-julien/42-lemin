/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempool_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:31:59 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/26 14:05:30 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns the pool element at the specified index.
*/

t_memunit	*get_by_index(t_mempool *mempool, size_t index)
{
	size_t	res;
	size_t	offset;

	offset = (size_t)(index * (mempool->unit_size + sizeof(t_memunit)));
	res = (size_t)&mempool->units;
	res += (size_t)offset;
	return ((t_memunit*)res);
}

t_mempool	*get_mempool_with_free_space(t_mempool *mempool)
{
	t_mempool	*curr;

	curr = mempool;
	while (curr != NULL)
	{
		if (curr->free != NULL)
			return (curr);
		curr = curr->extention;
	}
	return (NULL);
}
