/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:06:25 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 19:28:50 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	size_t	i;

	if (!src || !*src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1, int dir)
{
	int		j;
	char	*s1_dup;

	j = 0;
	s1_dup = (char *)malloc((ft_strlen(s1) - dir + 1) * sizeof(char));
	if (!s1_dup)
		return (NULL);
	while (s1[dir] != '\0')
		s1_dup[j++] = s1[dir++];
	s1_dup[j] = '\0';
	free(s1);
	return (s1_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i);
	else
		return (0);
}
