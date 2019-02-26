/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:44:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/26 13:58:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_glstdelone(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*next;

	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	next = (*alst)->next;
	mempool_free(*alst);
	*alst = next;
}
