/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 01:10:14 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/13 15:33:21 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isblank(int c)
{
	return (c == '\n' || c == ' ' || c == '\t');
}

static int	start_pos(char const *s)
{
	int		n;

	n = 0;
	while (isblank(s[n]))
		n++;
	return (n);
}

static int	end_pos(char const *s, int len)
{
	int		i;

	i = len - 1;
	while (i >= 0 && isblank(s[i]))
	{
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*result;

	if (s == NULL)
		return (NULL);
	start = start_pos(s);
	end = end_pos(s, ft_strlen((char*)s));
	len = end - start + 1;
	if (0 >= len)
		len = 0;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strncpy(result, (char*)(s + start), len);
	result[len] = '\0';
	return (result);
}
