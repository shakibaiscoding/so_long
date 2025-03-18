/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:52:36 by saghighi          #+#    #+#             */
/*   Updated: 2024/11/04 08:23:51 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int res, int digit, int sign)
{
	if (res > (INT_MAX - digit) / 10)
	{
		if (sign == 1)
			return (INT_MAX);
		else
			return (INT_MIN);
	}
	return (res * 10 + digit);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = check_overflow(res, *nptr - '0', sign);
		if (res == INT_MAX || res == INT_MIN)
			return (res);
		nptr++;
	}
	return (res * sign);
}
