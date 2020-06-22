/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:05:29 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 14:40:51 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_int_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_s2_begin(const char *s1, const char *set)
{
	int	s2_begin;

	s2_begin = 0;
	while (s1[s2_begin] != '\0')
	{
		if (ft_int_set(s1[s2_begin], set))
			s2_begin++;
		else
			return (s2_begin);
	}
	return (0);
}

static int	ft_s2_end(const char *s1, const char *set)
{
	int	s2_end;

	s2_end = ft_strlen(s1) - 1;
	while (s2_end >= 0)
	{
		if (ft_int_set(s1[s2_end], set))
			s2_end--;
		else
			return (s2_end + 1);
	}
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		s2_begin;
	int		s2_end;
	int		s2_len;
	char	*s2;

	i = 0;
	if (s1 == 0)
		return (0);
	s2_begin = ft_s2_begin(s1, set);
	s2_end = ft_s2_end(s1, set);
	s2_len = s2_end - s2_begin;
	s2 = (char*)malloc(sizeof(char) * (s2_len + 1));
	if (s2 == 0)
		return (0);
	while (i < s2_len)
	{
		s2[i] = s1[s2_begin + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
