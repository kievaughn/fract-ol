/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:16:06 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/12 18:54:40 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)s);
	if (start > src_len)
		return (ft_strdup(""));
	if (start == src_len)
	{
		string = (char *)malloc(1);
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	if (len > src_len - start)
		len = src_len - start;
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < len)
		string[i++] = s[start++];
	string[i] = '\0';
	return (string);
}
