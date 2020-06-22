/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:42:28 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/07 10:27:09 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == 0)
		return (0);
	while (*s1)
	{
		s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i++;
		s2++;
	}
	s3[i] = '\0';
	return (s3);
}
