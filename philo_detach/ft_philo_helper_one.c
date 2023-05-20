/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_helper_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:48:13 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/19 23:19:53 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	link_lst(t_philo **head)
{
	t_philo	*first;
	t_philo	*last;

	first = *head;
	last = *head;
	while (last-> next != NULL)
		last = last-> next;
	last -> next = first;
}

void	mk_lst(t_philo **h, t_list inpt, int *lock, pthread_mutex_t *mt_l)
{
	int		i;
	t_philo	*new;

	i = 0;
	while (i < inpt.philo_num)
	{
		new = ft_lstnew(i + 1);
		new->data = &inpt;
		new->lock = lock;
		new->death = mt_l;
		ft_lstadd_back(h, new);
		i++;
	}
	link_lst(h);
}

long long	get_time(int a)
{
	struct timeval	tv;

	(void)a;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	inits_st(t_list *philo, int *tab, int ac)
{
	int	i;

	i = 0;
	philo->philo_num = tab[i];
	i++;
	philo->t_die = tab[i];
	i++;
	philo->t_eat = tab[i];
	i++;
	philo->t_sleep = tab[i];
	philo->t_begin = get_time(1);
	i = 0;
	while (i < 4)
	{
		if (tab[i] <= 0)
			return (6);
		i++;
	}
	if (ac == 6)
	{
		philo->eat_time = tab[i];
		if (philo->eat_time <= 0)
			return (6);
	}
	return (0);
}

void	ft_m_sleep(long long t, t_philo *philo, long long time)
{
	long long	micro;

	(void)time;
	micro = get_time(1);
	while (get_time(1) - micro < t)
	{
		if (get_time(1) - philo->last_eat >= philo->data->t_die)
		{
			pthread_mutex_lock(philo->death);
			*(philo->lock) = 1;
			pthread_mutex_unlock(philo->death);
		}
		usleep(500);
	}
}
