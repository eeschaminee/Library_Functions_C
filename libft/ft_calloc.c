/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:14:59 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/14 13:22:26 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	int		i;

	i = 0;
	res = malloc(count * size);
	if (res == 0)
		return (0);
	while (i < (int)(count * size))
	{
		((char*)res)[i] = 0;
		i++;
	}
	return (res);
}
