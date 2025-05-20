/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:12:36 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/13 12:49:38 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	start_end(const char *s1, const char *set, int *start, int *end)
{
	*start = 0;
	*end = ft_strlen((char *)s1) - 1;
	while (s1[*start] && is_in_set(s1[*start], set))
		(*start)++;
	while (*end > *start && is_in_set(s1[*end], set))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*cpy;
	unsigned long int	i;
	int					start;
	int					end;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	start_end(s1, set, &start, &end);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	if (start > end)
		return (ft_strdup("\0"));
	cpy = malloc(end - start + 2);
	if (!cpy)
		return (NULL);
	i = 0;
	while (start <= end)
		cpy[i++] = s1[start++];
	cpy[i] = '\0';
	return (cpy);
}
