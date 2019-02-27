/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:44:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/26 20:00:27 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next != NULL)
		(*alst)->next->prev = NULL;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
