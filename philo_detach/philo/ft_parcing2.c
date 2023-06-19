/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:02:11 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 16:12:06 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') \
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnot_space_or_num(char c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 127))
		return (1);
	return (0);
}

int	ft_parcing_1(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '+' || tab[i][j] == '-')
				j++;
			if (!ft_isdigit(tab[i][j]))
				return (0);
			break ;
		}
		i++;
	}
	return (1);
}

int	ft_parcing_2(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) && ft_isnot_space_or_num(tab[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parcing_3(char **tab)
{
	int		i;
	long	n;

	i = 0;
	while (tab[i])
	{
		if (!tab[i])
			return (0);
		if (ft_str_is_alpha(tab[i]))
			return (0);
		n = ft_atoi(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
