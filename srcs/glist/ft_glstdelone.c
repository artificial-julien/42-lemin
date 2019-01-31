/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:44:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/30 18:30:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_glstdelone(t_glist **alst, void (*del)(void *, size_t))
{
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
