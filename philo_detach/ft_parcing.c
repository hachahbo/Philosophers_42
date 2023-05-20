/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 10:55:30 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/19 20:03:53 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_double(int *tab, t_ac *st)
{
	int	a;
	int	b;

	a = 0;
	while (a < st->size)
	{
		b = a + 1;
		while (b < st->size)
		{
			if (tab[a] == tab[b])
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

void	ft_parcing(char **tab)
{
	ft_parcing_1(tab);
	ft_parcing_2(tab);
	ft_parcing_3(tab);
}
