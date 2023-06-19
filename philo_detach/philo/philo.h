/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:34:52 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 16:11:00 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include  "./libft/libft.h"

typedef struct st_ac
{
	int	size;
}	t_ac;

int			check_char(char *c);
int			ft_size(char **ult_str);
char		*join_to_str(char **av, int ac);
char		*function_tojoin(char *result, char **av, int ac);
int			check_onlu_s(char *str);
void		error_help(int a);
char		*get_next_line(int fd);
char		*ft_read_str(int fd, char *str);
char		*ft_get_line(char *str);
char		*ft_new_str(char *str);
char		*ft_strchr(const char *s, int c);
int			*tableau(char **av, int ac);
int			check_f(char **av);
int			ft_beta_parcing(char **tab, int size);
int			ft_parcing(char **tab, int size);
int			ft_parcing_1(char **tab);
int			ft_parcing_2(char **tab);
int			ft_parcing_3(char **tab);
int			ft_str_is_alpha(char *str);
int			philosophers(t_philo *philo);
long long	get_time(int a);
void		mk_lst(t_philo **h, t_list inpt, int *lock, pthread_mutex_t *mt_l);
void		link_lst(t_philo **head);
int			inits_st(t_list *philo, int *tab, int ac);
int			ft_print_mutex(long long time, t_philo *philo, char *string);
void		ft_m_sleep(long long t, t_philo *philo, long long time);
void		*routine(void *arg);
int			activites_of_philos(t_philo *philo, unsigned long time);
int			ft_think(long long time, t_philo *philo);
int			ft_sleep(int x, unsigned long time, t_philo *philo);
int			ft_eat(int x, unsigned long time, t_philo *philo);

#endif