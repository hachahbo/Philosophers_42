/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:01 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/18 17:09:36 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] == c2[i] && c1[i] != 0 && c2[i] != 0)
		i++;
	return (c1[i] - c2[i]);
}

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

void	make_and_link_list(t_philo **head, t_list inpt, int *lock, pthread_mutex_t *mut_lock)
{
	int		i;
	t_philo	*new;
	i = 0;
	while (i < inpt.philo_num)
	{
		new = ft_lstnew(i+1);
		new->data = &inpt; 
		new->lock = lock;
		new->death = mut_lock;
		ft_lstadd_back(head, new);
		i++;
	}
	link_lst(head);
}

long long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int inits_st(t_list *philo, int *tab, int ac)
{
	int i = 0;
	philo->philo_num = tab[i];
	i++;
	philo->t_die = tab[i];
	i++;
	philo->t_eat = tab[i];
	i++;
	philo->t_sleep = tab[i];
	philo->t_begin = get_time();
	i = 0;
	while(i < 4)
	{
		if(tab[i] <= 0)
			return (6);
		i++;
	}
	
	if(ac == 6)
	{
		philo->eat_time = tab[i];
		if (philo->eat_time <= 0)
			return (6);
	}
	return(0);
}

int	ft_print_mutex(long long time, t_philo *philo,char *string)
{
	pthread_mutex_lock(philo->death);
	// if(*(philo->lock) == 0)
	// {
		printf("%llu %d %s \n",get_time() - time, philo->id, string);
		pthread_mutex_unlock(philo->death);
		return (0);
	// }
	pthread_mutex_unlock(philo->death);
	return (1);
}

void ft_m_sleep(long long t, t_philo *philo, long long time)
{
	long long micro;

	(void)time;
	micro = get_time();
	while(get_time() - micro < t)
	{
		if(get_time() - philo->last_eat >= philo->data->t_die)
		{
			// pthread_mutex_lock(philo->death);
			// if (*(philo->lock) == 1)
			// {
			// 	pthread_mutex_unlock(philo->death);
			// 	return ;
			// }
			pthread_mutex_lock(philo->death);
			*(philo->lock) = 1;
			pthread_mutex_unlock(philo->death);
			// 	printf("%llu %d is dead \n",get_time() - time, philo->id);
			// pthread_mutex_unlock(philo->death);
		}
		usleep(500);
	}
}

int ft_eat(int x, unsigned long time, t_philo *philo)
{
	if(ft_print_mutex(time, philo, "is eating"))
		return (1);
	ft_m_sleep(x, philo, time);
	return (0);
}

int ft_sleep(int x,unsigned long time , t_philo *philo)
{
	if(ft_print_mutex(time, philo, "is sleeping"))
		return (1);
 	ft_m_sleep(x, philo, time);
	return (0);
}

int ft_think(long long time, t_philo *philo)
{
	if (ft_print_mutex(time, philo, "is thinking"))
		return (1);
	return (0);
}
int activites_of_philos(t_philo  *philo, unsigned long time)
{
	int i;
	int c = 0;

	while(c < 3)
	{
		i = 0;
		while(i < philo->data->eat_time)
		{	
		if(ft_eat(philo->data->t_eat, time, philo))
			return (0);
		philo->last_eat = get_time();
 		if(ft_sleep(philo->data->t_sleep, time, philo))
			return (0);
		if(ft_think(time, philo))
			return (0);
		i++;
		}
		c++;
	}
	return (1);
}
void * routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	unsigned long time = philo->data->t_begin;
	philo->last_eat = get_time();
	if(philo->id % 2 == 0)
		usleep(200);
	while(1)
	{
		pthread_mutex_lock(&philo->fork);
		ft_print_mutex(time, philo, "has taken a fork");
		if(philo->data->philo_num == 1)
		{
			ft_print_mutex(time, philo, "is dead");
			pthread_mutex_unlock(&philo->fork);
			return(0);
		}
		pthread_mutex_lock(&philo->next->fork);
		ft_print_mutex(time, philo, "has taken a fork");
		if(philo->data->eat_time != 0)
		{
			activites_of_philos(philo, time);
			pthread_mutex_lock(philo->death);
			*(philo->lock) = 2;
			pthread_mutex_unlock(philo->death);
			return (0);
		}
		if(ft_eat(philo->data->t_eat, time, philo))
			return (NULL);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
 		if(ft_sleep(philo->data->t_sleep, time, philo))
			return (NULL);
		if(ft_think(time, philo))
			return (NULL);
	}
	return NULL;
}

int philosophers(t_philo *philo)
{
	t_philo *help;
	help = philo;
	int i = help->data->philo_num;
	while (i)
	{
		pthread_mutex_init(&philo->fork, NULL);
		pthread_create(&philo->ph, NULL, &routine, philo);
		pthread_detach(philo->ph);
		philo = philo->next;
		i--;
	}
	philo = help;
	// while(i)
	// {
	// 	pthread_join(philo->ph, NULL);
	// 	philo  = philo->next;
	// 	i--;
	// }
	return (0);
}
int main(int ac, char **av)
{
	t_list	inpt;
	t_philo	*philo;
	s_ac	st;
	int		*tab;
	pthread_mutex_t mut_lock;
	int lock;

	if(ac != 5 && ac != 6)
		return(0);
	tab = tableau(av, ac, &st);
	memset(&inpt, 0, sizeof(t_list));
	lock = 0;
	if(inits_st(&inpt, tab, ac))
		return (0);
	philo = NULL;
	pthread_mutex_init(&mut_lock, NULL);
	make_and_link_list(&philo, inpt, &lock, &mut_lock);
	philosophers(philo);
	while(1)
	{
		pthread_mutex_lock(philo->death);
		if (inpt.philo_num == 1)
		{
			usleep(500);	
			pthread_mutex_unlock(philo->death);
			return (0);
		}
		pthread_mutex_unlock(philo->death);
		pthread_mutex_lock(philo->death);
		if (*(philo->lock)== 2)
		{
			pthread_mutex_unlock(philo->death);
			return (0);
		}
		pthread_mutex_unlock(philo->death);
		
		pthread_mutex_lock(philo->death);
		if (*(philo->lock) == 1)
		{
			pthread_mutex_unlock(philo->death);
			pthread_mutex_lock(philo->death);
			printf("%llu %d is dead \n",get_time() - inpt.t_begin, philo->id);
			// pthread_mutex_unlock(philo->death);
			return (0);
		}
		pthread_mutex_unlock(philo->death);
		usleep(100);
	}
}
