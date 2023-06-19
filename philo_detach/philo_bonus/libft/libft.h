/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:20:07 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/19 19:36:59 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <semaphore.h>

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

int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strnstr(const char *haystack, const char \
				*needle, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
long			ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_philo			*ft_lstnew(int content);
void			ft_lstadd_front(t_philo **lst, t_philo *new);
t_philo			*ft_lstlast(t_philo *lst);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
int				ft_lstsize(t_philo *lst);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
