/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:03:03 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 19:31:30 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Converts the specified list to an array of pointers.
*/

void			*glist_to_array(t_glist *list)
{
	void	**res;
	size_t	pos;
	size_t	size;
	t_glist	*curr;

	size = ft_glstlen(list);
	res = ft_memalloc(((size) * sizeof(void*)));
	pos = 0;
	curr = list;
	while (curr != NULL)
	{
		res[pos] = curr->content;
		pos++;
		curr = curr->next;
	}
	return (res);
}

static void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool	sort_pass(void **array, size_t size, int (cmp)(void*, void*))
{
	t_bool	res;
	size_t	pos;

	res = true;
	pos = 0;
	while (pos < size - 1)
	{
		if (cmp(array[pos], array[pos + 1]) > 0)
		{
			res = false;
			swap(&array[pos], &array[pos + 1]);
		}
		pos++;
	}
	return (res);
}

/*
**	Runs a bubble sort over the specified array.
*/

void			array_sort(void **array, size_t size, int (cmp)(void*, void*))
{
	size_t	pos;

	pos = 0;
	while (pos < size)
	{
		if (sort_pass(array, size - pos, cmp))
			return ;
		pos++;
	}
}
