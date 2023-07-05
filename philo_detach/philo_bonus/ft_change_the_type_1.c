/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_the_type_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:29:23 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/05 10:23:42 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <limits.h>

int	ft_beta_parcing(char **tab, int size)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (!check_char(tab[j++]))
			return (0);
	}
	j = 0;
	while (tab[0][j])
	{
		if (ft_atoi(tab[0]) < INT_MIN || ft_atoi(tab[0]) > INT_MAX)
			return (0);
		j++;
	}
	if (size == 1)
		return (0);
	return (1);
}

int	check_f(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{	
		if (av[i][0] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_ulst(char **ult_str, int *t, char *str)
{
	int	i;

	i = 0;
	while (ult_str[i])
	{
		free(ult_str[i]);
		i++;
	}
	free(t);
	free(str);
	free(ult_str);
}

int	*tableau(char **av, int ac)
{
	char	**ult_str;
	int		*t;
	int		i;
	char	*str;
	t_ac	st;

	str = join_to_str(av, ac);
	if (str == 0)
		return (0);
	ult_str = ft_split(str, ' ');
	st.size = ft_size(ult_str);
	t = (int *)malloc(st.size * sizeof(int));
	if (!t)
		return (free(t), NULL);
	i = 0;
	if (!ft_parcing(ult_str, st.size))
		return (ft_free_ulst(ult_str, t, str), NULL);
	while (ult_str[i])
	{
		t[i] = ft_atoi(ult_str[i]);
		free(ult_str[i]);
		i++;
	}
	return (free(str), free(ult_str), t);
}
