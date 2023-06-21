/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:14:20 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/20 11:26:58 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "limits.h"

int	is_overflow(long int prv, long int res)
{
	if (res / 10 != prv)
		return (1);
	return (0);
}

void	ft_sign_space(char *str, long *i, long *sign)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		*i += 1;
	if (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			*sign *= -1;
			*i += 1;
	}
}

long	ft_atoi(const char *str)
{
	long int	res;
	long		sign;
	long		i;
	long int	prv;

	i = 0;
	res = 0;
	sign = 1;
	ft_sign_space((char *)str, &i, &sign);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		prv = res;
		res = res * 10 + str[i++] - '0';
		if (is_overflow(prv, res) == 1)
			return (LONG_MAX);
	}
	return (res * sign);
}
