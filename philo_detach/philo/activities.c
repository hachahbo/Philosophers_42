/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:45:35 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/21 12:45:51 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(int x, unsigned long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is eating"))
		return (1);
	ft_m_sleep(x, philo, time);
	return (0);
}

int	ft_sleep(int x, unsigned long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is sleeping"))
		return (1);
	ft_m_sleep(x, philo, time);
	return (0);
}

int	ft_think(long long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is thinking"))
		return (1);
	return (0);
}
