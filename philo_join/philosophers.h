/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:34:52 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/13 22:56:43 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
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
} s_ac;

void	check_char(char *c);
int		ft_size(char **ult_str);
char	*join_to_str(char **av, int ac);
char	*function_tojoin(char *result, char **av, int ac);
void	check_onlu_s(char *str);
void	error_help(int a);
char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);
char	*ft_strchr(const char *s, int c);
int		*tableau(char **av, int ac, s_ac *st);
void	check_f(char **av);
void	ft_beta_parcing(char **tab);
void	ft_error();
void	ft_parcing(char **tab, s_ac *st);
void	ft_parcing_1(char **tab);
void	ft_parcing_2(char **tab);
void	ft_parcing_3(char **tab);
int		ft_str_is_alpha(char *str);

#endif