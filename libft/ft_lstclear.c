/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 10:51:11 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 14:06:02 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	t_list *list;

	if (lst == 0)
		return ;
	list = *lst;
	while (list != 0)
	{
		next = list->next;
		if (list->content != 0)
			del(list->content);
		free(list);
		list = next;
	}
	*lst = 0;
}
