/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:22 by hachahbo          #+#    #+#             */
/*   Updated: 2023/06/20 16:01:29 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_lstclear(t_philo **lst)
{
	t_philo	*temp;
	t_philo	*freed;

	temp = *lst;
	while (temp != NULL)
	{
		freed = temp;
		temp = temp->next;
		free(freed);
	}
	*lst = NULL;
}
