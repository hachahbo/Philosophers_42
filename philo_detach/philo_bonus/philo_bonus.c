/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:01 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 23:17:03 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_print_mutex(long long time, t_philo *philo, char *string)
{
	sem_wait(philo->death);
	printf("%llu %d %s\n", get_time(1) - time, philo->id, string);
	if (get_time(1) - philo->last_eat < philo->data->t_die)
		sem_post(philo->death);
	return (0);
}

int	philosophers(t_philo *philo)
{
	t_philo	*help;
	int		i;
	sem_t	*sem;
	sem_t	*death;
	pid_t	child_p;
	

	help = philo;
	sem = sem_open("/fork", O_CREAT | O_EXCL, 0666, philo->data->philo_num);
	death = sem_open("/death", O_CREAT | O_EXCL, 0666, 1);
	i = help->data->philo_num;
	while (i)
	{
		child_p = fork();
		if(child_p == 0)
		{
			philo->pid= getpid();
			philo->fork = sem;
			philo->death = death;
			routine(philo);
		}
		philo = philo->next;
		i--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list			inpt;
	t_philo			*philo;
	int				*tab;
	int				i;

	if (ac != 5 && ac != 6)
		return (0);
	tab = tableau(av, ac);
	if (tab == 0)
		return (0);
	if (inits_st(&inpt, tab, ac))
		return (0);
	free(tab);
	philo = NULL;
	mk_lst(&philo, inpt);
	philosophers(philo);
	// usleep(500);
	waitpid(-1, 0, 0);
	i = 0;
	// while(i < philo->data->philo_num)
	// {
	// 	if(philo->pid != 0)
	// 	{
	// 		kill(philo->pid, SIGTERM);
	// 	}
	// 	i++;
	// 	philo = philo->next;
	// }
	return (0);
}
