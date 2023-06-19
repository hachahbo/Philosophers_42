/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:01 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 16:12:16 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_mutex(long long time, t_philo *philo, char *string)
{
	pthread_mutex_lock(philo->death);
	printf("%llu %d %s\n", get_time(1) - time, philo->id, string);
	pthread_mutex_unlock(philo->death);
	return (0);
}

int	philosophers(t_philo *philo)
{
	t_philo	*help;
	int		i;

	help = philo;
	i = help->data->philo_num;
	while (i)
	{
		pthread_mutex_init(&philo->fork, NULL);
		pthread_create(&philo->ph, NULL, &routine, philo);
		pthread_detach(philo->ph);
		philo = philo->next;
		i--;
	}
	return (0);
}

int	ft_detach(t_philo *philo, t_list inpt)
{
	while (1)
	{
		pthread_mutex_lock(philo->death);
		if (inpt.philo_num == 1)
			return (pthread_mutex_unlock(philo->death), 0);
		pthread_mutex_unlock(philo->death);
		pthread_mutex_lock(philo->death);
		if (*(philo->lock) == 2)
			return (pthread_mutex_unlock(philo->death), 0);
		pthread_mutex_unlock(philo->death);
		pthread_mutex_lock(philo->death);
		if (*(philo->lock) == 1)
		{
			pthread_mutex_unlock(philo->death);
			pthread_mutex_lock(philo->death);
			printf("%llu %d died \n", get_time(1) - inpt.t_begin, philo->id);
			return (0);
		}
		pthread_mutex_unlock(philo->death);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_list			inpt;
	t_philo			*philo;
	int				*tab;
	pthread_mutex_t	mut_lock;
	int				lock;

	if (ac != 5 && ac != 6)
		return (0);
	tab = tableau(av, ac);
	if (tab == 0)
		return (0);
	memset(&inpt, 0, sizeof(t_list));
	lock = 0;
	if (inits_st(&inpt, tab, ac))
		return (0);
	free(tab);
	philo = NULL;
	pthread_mutex_init(&mut_lock, NULL);
	mk_lst(&philo, inpt, &lock, &mut_lock);
	philosophers(philo);
	usleep(500);
	ft_detach(philo, inpt);
	return (0);
}
