/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:08:33 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/21 12:45:27 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (1);
}

int	check_number_philo(t_philo *philo, unsigned long time)
{
	if (philo->data->philo_num == 1)
	{
		ft_print_mutex(time, philo, "died");
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}
	return (1);
}

int	check_eat_time(t_philo *philo, unsigned long time)
{
	if (philo->data->eat_time != 0)
	{
		activites_of_philos(philo, time);
		pthread_mutex_lock(philo->death);
		*(philo->lock) = 2;
		pthread_mutex_unlock(philo->death);
		return (0);
	}
	return (1);
}

int	take_fork_and_eat(t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(&philo->fork);
	ft_print_mutex(time, philo, "has taken a fork");
	if (!check_number_philo(philo, time))
		return (0);
	pthread_mutex_lock(&philo->next->fork);
	ft_print_mutex(time, philo, "has taken a fork");
	if (!check_eat_time(philo, time))
		return (0);
	if (ft_eat(philo->data->t_eat, time, philo))
		return (0);
	philo->last_eat = get_time(1);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	return (1);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	unsigned long	time;

	philo = (t_philo *)arg;
	time = philo->data->t_begin;
	philo->last_eat = get_time(1);
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		if (!take_fork_and_eat(philo, time))
			return (0);
		if (ft_sleep(philo->data->t_sleep, time, philo))
			return (NULL);
		if (ft_think(time, philo))
			return (NULL);
	}
	return (NULL);
}
