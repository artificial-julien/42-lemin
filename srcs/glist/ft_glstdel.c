/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:47:48 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/13 16:12:28 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_glstdel(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*curr;
	t_glist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_glstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
