/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:48:08 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/21 12:55:10 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_eat(int x, unsigned long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is eating"))
		exit (0);
	ft_m_sleep(x, philo, time);
	return (0);
}

int	ft_sleep(int x, unsigned long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is sleeping"))
		exit (0);
	ft_m_sleep(x, philo, time);
	return (0);
}

int	ft_think(long long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is thinking"))
		exit (0);
	return (0);
}
