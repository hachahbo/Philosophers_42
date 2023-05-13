/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:01 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/13 23:11:14 by hachahbo         ###   ########.fr       */
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
// void	printlist(t_philo *list)
// {
// 	while (list)
// 	{
// 		ft_print_mutex("philosopher number %d \n", list->id);
// 		list = list->next;
// 	}
// }
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
void	make_and_link_list(t_philo **head, t_list inpt, int *lock)
{
	int		i;
	t_philo	*new;
	pthread_mutex_t mut_lock;
	pthread_mutex_init(&mut_lock, NULL);
	i = 0;
	while (i < inpt.philo_num)
	{
		new = ft_lstnew(i+1);
		new->data = inpt; 
		new->lock = lock;
		new->death = &mut_lock;
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
	if(ac == 6)
	{
		i++;
		philo->eat_time = tab[i];
		if (philo->eat_time <= 0)
			return (6);
	}
	return(0);
}
void ft_print_mutex(long long time, t_philo *philo,char *string)
{
	pthread_mutex_lock(philo->death);
	printf("%llu philosopher id : %d %s 🍲 \n",get_time() - time, philo->id, string);
	if(*(philo->lock) == 0)
		pthread_mutex_unlock(philo->death);
}
void ft_m_sleep(long long t, t_philo *philo, long long time)
{
	long long micro;

	micro = get_time();
	while(get_time() - micro < t)
	{
		if(get_time() - philo->last_eat >= philo->data.t_die)
		{
			*(philo->lock) = 1;
			ft_print_mutex(time, philo, "is death");
		}
	}
}
void ft_eat(int x, unsigned long time, t_philo *philo)
{
	ft_print_mutex(time, philo, "is eating");
	ft_m_sleep(x, philo, time);
}
void ft_sleep(int x,unsigned long time , t_philo *philo)
{
	ft_print_mutex(time, philo, "is sleeping");
 	ft_m_sleep(x, philo, time);
}
void ft_think(long long time, t_philo *philo)
{
	ft_print_mutex(time, philo, "is thinking");
}
void * routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	unsigned long time = get_time();
	if(philo->id % 2 == 0)
		usleep(200);
	while(1)
	{
		philo->last_eat = get_time();
		pthread_mutex_lock(&philo->fork);
		printf("%llu philo %d taken fork 🍴\n", get_time() - time, philo->id);
		pthread_mutex_lock(&philo->next->fork);
		printf("%llu philo %d taken fork's  🍴 id : %d \n",get_time() - time, philo->id, philo->next->id);
		ft_eat(philo->data.t_eat, time, philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
 		ft_sleep(philo->data.t_sleep, time, philo);
		ft_think(time, philo);
	}
	return NULL;
}

int philosophers(t_philo *philo)
{
	t_philo *help;
	// pthread_mutex_t lock;
	
	// pthread_mutex_init(&lock, NULL);
	help = philo;
	int i = help->data.philo_num;
	while (i)
	{
		pthread_mutex_init(&philo->fork, NULL);
		pthread_create(&philo->ph, NULL, &routine, philo);
		philo = philo->next;
		i--;
	}
	philo = help;
	i = help->data.philo_num;
	while(i)
	{
		pthread_join(philo->ph, NULL);
		philo  = philo->next;
		i--;
	}
	while(1)
	{
		
	}
	return (0);
}
int main(int ac, char **av)
{
	t_list inpt;
	t_philo *philo;
	s_ac	st;
	int		*tab;
	int lock;

	if(ac != 5 && ac != 6)
		printf("invalid inputs \n");
	tab = tableau(av, ac, &st);
	memset(&inpt, 0, sizeof(t_list));
	lock = 0;
	inits_st(&inpt, tab, ac);
	philo = NULL;
	make_and_link_list(&philo, inpt, &lock);
	philosophers(philo);
}
