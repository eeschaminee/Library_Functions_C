/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:12:37 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 14:44:45 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_free(t_list *new_list, void (*del)(void *))
{
	t_list *next;

	while (new_list != 0)
	{
		next = new_list->next;
		del(new_list->content);
		free(new_list);
		new_list = next;
	}
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*new_content;

	new_list = 0;
	if (lst == 0)
		return (0);
	while (lst != 0)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (new_elem == 0)
			break ;
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
		if (lst == 0)
			return (new_list);
	}
	ft_free(new_list, del);
	return (0);
}
