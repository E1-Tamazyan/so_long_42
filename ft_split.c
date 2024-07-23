/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:10:43 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/06 11:05:01 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		sub = (char *)malloc(ft_strlen(s));
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

static size_t	count_tokens(char const *str, char delimeter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*str)
	{
		inside_token = 0;
		while (*str && *str == delimeter)
			++str;
		while (*str && *str != delimeter)
		{
			if (!inside_token)
			{
				tokens++;
				inside_token = 1;
			}
			++str;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	const char	*new_s;
	char		**arr;
	int			words_amount;
	int			i;

	if (!s)
		return (NULL);
	words_amount = count_tokens(s, c);
	arr = (char **)malloc((words_amount + 1) * (sizeof(char *)));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < words_amount)
	{
		while (*s == c)
			s++;
		new_s = s;
		while (*s && *s != c)
			s++;
		arr[i] = ft_substr(new_s, 0, s - new_s);
		if (!arr[i] && ft_split(*arr, i))
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}
