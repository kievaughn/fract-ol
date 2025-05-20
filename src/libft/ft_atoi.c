/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:44:03 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/12 18:54:40 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	mult;
	int	nbr;

	i = 0;
	mult = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (0);
		if (str[i] == 45)
			mult *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + ((str[i++]) - '0');
	}
	nbr *= mult;
	return (nbr);
}
