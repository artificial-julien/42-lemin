/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:21:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/27 15:18:10 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Extends an existing memory pool.
*/

static t_mempool	*mempool_extend(t_mempool *mempool, size_t extra_unit_count)
{
	t_mempool	*res;

	ft_fprintf(2, "Extending pool\n");
	res = mempool_new(extra_unit_count, mempool->unit_size);
	mempool->extention = res;
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
	res->extention = NULL;
	unit = &res->units[0];
	i = 0;
	while (i < unit_count - 1)
	{
		get_by_index(res, i)->mempool = res;
		get_by_index(res, i)->next = get_by_index(res, i + 1);
		i++;
	}
	get_by_index(res, i)->mempool = res;
	get_by_index(res, i)->next = NULL;
	return (res);
}

/*
**	Liberates the pool and its extentions.
*/

void				mempool_del(t_mempool *mempool)
{
	if (mempool->extention != NULL)
	{
		mempool_del(mempool->extention);
	}
	free(mempool);
}

/*
**	Returns a new element from the pool.
*/

void				*mempool_alloc(t_mempool *mempool)
{
	t_mempool	*target_pool;
	t_memunit	*old_free;
	void		*res;

	target_pool = get_mempool_with_free_space(mempool);
	if (target_pool == NULL)
	{
		target_pool = mempool_extend(mempool, mempool->unit_count);
	}
	res = &target_pool->free->content;
	old_free = target_pool->free;
	target_pool->free = target_pool->free->next;
	old_free->next = NULL;
	return (res);
}

/*
**	Liberates the specified address in the pool.
*/

void				mempool_free(void *ptr)
{
	t_memunit	*prev;
	t_memunit	*unit;
	t_mempool	*mempool;

	unit = ptr - sizeof(t_memunit);
	mempool = unit->mempool;
	prev = mempool->free;
	mempool->free = unit;
	mempool->free->next = prev;
}

