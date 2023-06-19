/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_the_type_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:47:55 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 16:10:27 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_onlu_s(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			a += 1;
		i++;
	}
	if (a == 0)
		return (0);
	return (1);
}

char	*function_tojoin(char *result, char **av, int ac)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = 2;
	while (i < ac)
	{
		temp = ft_strjoin(result, av[i]);
		temp2 = ft_strjoin(temp, " ");
		free (result);
		free (temp);
		result = temp2;
		i++;
	}
	return (result);
}

char	*join_to_str(char **av, int ac)
{
	char	*result;
	int		i;

	if (!check_f(av))
		return (0);
	i = 1;
	while (i < ac)
	{
		if (av[i] == 0)
			return (0);
		i++;
	}
	result = ft_strjoin(av[1], " ");
	i = 1;
	while (i < ac)
	{
		if (!check_onlu_s(av[i]))
			return (0);
		i++;
	}
	result = function_tojoin(result, av, ac);
	return (result);
}

int	ft_size(char **ult_str)
{
	int	i;

	i = 0;
	while (ult_str[i])
		i++;
	return (i);
}

int	check_char(char *c)
{
	int	a;

	a = 0;
	while (c[a] == ' ' || c[a] == '\t')
	{
		if (!(c[a] == ' ' || c[a] == '\t'))
			return (0);
		a++;
	}
	while (c[a] == ' ' || c[a] == '\t' || c[a] == '+' || c[a] == '-')
	{
		if ((c[a] == '+' || c[a] == '-') && ft_isdigit(c[a + 1]) == 0)
			return (0);
		a++;
	}
	while (c[a])
	{
		if (!ft_isdigit(c[a]))
			return (0);
		a++;
	}
	return (1);
}
