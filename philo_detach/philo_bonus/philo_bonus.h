/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:34:52 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/20 15:50:59 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <semaphore.h>

typedef struct st_ac
{
	int	size;
}	t_ac;

typedef struct k_list
{
	int			philo_num;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			eat_time;
	long long	t_begin;
}	t_list;

typedef struct o_phil
{
	int				id;
	sem_t			*fork;
	sem_t			*death;
	pid_t			pid;
	int				last_eat_time;
	t_list			*data;
	long long		last_eat;
	int				meals;
	sem_t			*lock;
	struct o_phil	*next;
}	t_philo;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_lstlast(t_philo *lst);
t_philo		*ft_lstnew(int content);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
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
void		mk_lst(t_philo **head, t_list inpt);
void		link_lst(t_philo **head);
int			inits_st(t_list *philo, int *tab, int ac);
int			ft_print_mutex(long long time, t_philo *philo, char *string);
void		ft_m_sleep(long long t, t_philo *philo, long long time);
int			routine(t_philo *philo);
int			activites_of_philos(t_philo *philo, unsigned long time);
int			ft_think(long long time, t_philo *philo);
int			ft_sleep(int x, unsigned long time, t_philo *philo);
int			ft_eat(int x, unsigned long time, t_philo *philo);

#endif