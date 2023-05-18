/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:13:21 by hachahbo          #+#    #+#             */
/*   Updated: 2023/05/09 09:04:25 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main(void)
// {
// 	t_list *list = NULL;
// 	t_list *new1 = malloc(sizeof(t_list));
// 	t_list *new2 = malloc(sizeof(t_list));

// 	if (!new1 || !new2)
// 		return (1);

// 	new1->content = "Hello";
// 	new1->next = NULL;

// 	new2->content = "World";
// 	new2->next = NULL;

// 	ft_lstadd_front(&list, new1);
// 	ft_lstadd_front(&list, new2);

// 	printf("\nList after adding new elements:\n");
// 	while (list)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}

// 	free(new1);
// 	free(new2);

// 	return (0);
// }