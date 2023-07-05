/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:08:33 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/05 10:37:49 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	activites_of_philos(t_philo *philo, unsigned long time)
{
	int	i;
	int	c;
	int	l;

	c = 0;
	l = 2;
	if (philo->data->philo_num % 2 == 1)
		l = 3;
	while (c < l)
	{
		i = 0;
		while (i < philo->data->eat_time)
		{	
			if (ft_eat(philo->data->t_eat, time, philo))
				return (0);
			philo->last_eat = get_time(1);
			if (ft_sleep(philo->data->t_sleep, time, philo))
				return (0);
			if (ft_think(time, philo))
				return (0);
			i++;
		}
		c++;
	}
	exit (0);
}

void	check_the_death(t_philo *philo, long long time)
{
	if (get_time(1) - philo->last_eat >= philo->data->t_die)
	{
		ft_print_mutex(time, philo, "is dead");
		sem_unlink("/fork");
		sem_unlink("/death");
		exit(0);
	}
}

int	take_fork_and_eat(t_philo *philo, unsigned long time)
{
	sem_wait(philo->fork);
	ft_print_mutex(time, philo, "has taken a fork");
	if (philo->data->philo_num == 1)
	{
		ft_print_mutex(get_time(1) - philo->data->t_die, philo, "died");
		return (0);
	}
	sem_wait(philo->fork);
	ft_print_mutex(time, philo, "has taken a fork");
	if (philo->data->eat_time != 0)
		activites_of_philos(philo, time);
	ft_eat(philo->data->t_eat, time, philo);
	check_the_death(philo, time);
	philo->last_eat = get_time(1);
	sem_post(philo->fork);
	sem_post(philo->fork);
	return (1);
}

int	routine(t_philo *philo)
{
	unsigned long	time;

	time = philo->data->t_begin;
	philo->last_eat = get_time(1);
	if (philo->id % 2 == 0)
		ft_m_sleep(philo->data->t_eat, philo, time);
	while (1)
	{
		if (!take_fork_and_eat(philo, time))
			return (0);
		ft_sleep(philo->data->t_sleep, time, philo);
		ft_think(time, philo);
		if (philo->data->t_eat > philo->data->t_sleep)
			ft_sleep(philo->data->t_eat - philo->data->t_sleep, time, philo);
	}
	return (0);
}
