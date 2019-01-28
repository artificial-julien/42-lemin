/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 01:32:36 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 15:59:11 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char const *str, char separator)
{
	int i;

	i = 0;
	while (str[i] != 0 && str[i] != separator)
	{
		i++;
	}
	return (i);
}

static int		get_word_count(char const *str, char separator)
{
	int word_len;
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		word_len = get_word_len(str + i, separator);
		if (word_len > 0)
		{
			n++;
			i += word_len;
		}
		else
		{
			i++;
		}
	}
	return (n);
}

static char		*try_create_word(char const *str, char separator, int *word_len)
{
	char	*result;

	*word_len = get_word_len(str, separator);
	if (*word_len > 0)
	{
		result = malloc(*word_len + 1);
		ft_strncpy(result, str, *word_len);
		*(result + (*word_len)) = '\0';
		str += (*word_len);
		return (result);
	}
	return (NULL);
}

char			**ft_strsplit(char const *str, char separator)
{
	int		i;
	int		word_count;
	int		word_len;
	char	**result;

	if (str == NULL)
		return (NULL);
	word_count = get_word_count(str, separator);
	result = malloc(sizeof(char*) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		result[i] = try_create_word(str, separator, &word_len);
		if (result[i] != NULL)
		{
			str += word_len;
			i++;
		}
		else
			str += 1;
	}
	result[i] = 0;
	return (result);
}
