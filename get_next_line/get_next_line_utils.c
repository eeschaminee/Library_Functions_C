/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:44:43 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/20 14:54:51 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
	}
	else
	{
		while (i < (int)len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s1, size_t size)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char*)malloc(size + 1);
	if (s2 == 0)
		return (0);
	while (i < (int)size && s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_char_position(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strnappend(char **s1, char const *s2, int n2)
{
	int		i;
	char	*s3;

	i = 0;
	if (*s1 == 0 || s2 == 0)
		return (0);
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(*s1) + n2 + 1));
	if (s3 == 0)
		return (0);
	while ((*s1)[i] != '\0')
	{
		s3[i] = (*s1)[i];
		i++;
	}
	while (*s2 && n2 > 0)
	{
		s3[i] = *s2;
		i++;
		s2++;
		n2--;
	}
	s3[i] = '\0';
	free(*s1);
	*s1 = s3;
	return (1);
}
