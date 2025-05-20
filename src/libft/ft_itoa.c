/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:32:33 by kbrandon          #+#    #+#             */
/*   Updated: 2024/11/13 12:48:40 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char	*neg(int n)
{
	char	*str;
	int		i;

	i = get_digits(n);
	str = ft_calloc((i + 2), 1);
	if (!str)
		return (NULL);
	n *= -1;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

static char	*pos(int n)
{
	char	*str;
	int		i;

	i = get_digits(n) - 1;
	str = ft_calloc((i + 2), 1);
	if (!str)
		return (NULL);
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0)
		str = pos(n);
	if (n < 0)
		str = neg(n);
	return (str);
}
