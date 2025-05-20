/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:13:32 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/12 19:45:53 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;
	int		strlen;

	if (!s)
		return ;
	if (fd < 0)
		return ;
	ptr = s;
	strlen = 0;
	while (*ptr != '\0')
	{
		ptr++;
		strlen++;
	}
	write(fd, s, strlen);
}
