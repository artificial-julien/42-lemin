/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_total_rounds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:11:36 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 15:01:12 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns the number of rounds taken for the ants to reach the end
**	using the specified group.
**	Requires group with size ascendant ordered routes.
*/

int			group_total_rounds(t_group *group, int total_ants)
{
	int	size;
	int	*array;
	int	res;

	size = ants_distribution(group, total_ants, &array);
	res = array[0] + group->routes->route->len;
	free(array);
	return (res);
}
