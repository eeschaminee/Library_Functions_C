/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:51:54 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 14:17:45 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == 0)
		return (0);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
