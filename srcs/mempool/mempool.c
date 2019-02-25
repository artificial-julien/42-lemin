/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:21:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/25 18:15:23 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns the pool element at the specified index.
*/

static t_memunit	*get_by_index(t_mempool *mempool, size_t index)
{
	size_t	res;
	size_t	offset;

	offset = (size_t)(index * (mempool->unit_size + sizeof(t_memunit)));
	res = (size_t)&mempool->units;
	res += (size_t)offset;
	return ((t_memunit*)res);
}

/*
**	Extends an existing memory pool.
**	Not implemented.
*/

static t_mempool	*mempool_extend(t_mempool *mempool, size_t extra_unit_count)
{
	t_mempool	*res;

	res = mempool_new(extra_unit_count, mempool->unit_size);
	ft_fprintf(2, "throw new NotImplementedException();\n");
	exit(EXIT_FAILURE);
	return (res);
}

/*
**	Creates a new pool.
*/

t_mempool			*mempool_new(size_t unit_count, size_t unit_size)
{
	t_mempool	*res;
	size_t		total_unit_size;
	size_t		i;
	t_memunit	*unit;

	total_unit_size = unit_count * (sizeof(t_memunit) + unit_size);
	res = ft_safe_malloc(sizeof(t_mempool) + total_unit_size);
	res->free = &res->units[0];
	res->unit_count = unit_count;
	res->unit_size = unit_size;
	unit = &res->units[0];
	i = 0;
	while (i < unit_count)
	{
		if (i < unit_count - 1)
			get_by_index(res, i)->next = get_by_index(res, i + 1);
		else
			get_by_index(res, i)->next = NULL;
		i++;
	}
	return (res);
}

/*
**	Returns a new element from the pool.
*/

void				*mempool_alloc(t_mempool *mempool)
{
	t_mempool	*new;
	t_memunit	*old_free;
	void		*res;

	if (mempool->free == NULL)
	{
		new = mempool_extend(mempool, mempool->unit_count);
		free(mempool);
		mempool = new;
	}
	res = &mempool->free->content;
	old_free = mempool->free;
	mempool->free = mempool->free->next;
	old_free->next = NULL;
	return (res);
}

/*
**	Liberates the specified address in the pool.
*/

void				mempool_free(t_mempool *mempool, void *content)
{
	t_memunit	*prev;
	t_memunit	*unit;

	unit = content - sizeof(t_memunit);
	prev = mempool->free;
	mempool->free = unit;
	mempool->free->next = prev;
}

