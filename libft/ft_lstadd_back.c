/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:38:04 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/07 12:36:42 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	l = *alst;
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	while (l->next != 0)
		l = l->next;
	l->next = new;
}
