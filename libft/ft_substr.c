/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:25:59 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/13 13:54:03 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*substr;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len <= s_len)
		substr = (char*)malloc(sizeof(char) * (len + 1));
	else
		substr = (char*)malloc(sizeof(char) * (s_len - start + 1));
	if (substr == 0)
		return (0);
	while ((i < len) && (s[i + start] != '\0'))
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
