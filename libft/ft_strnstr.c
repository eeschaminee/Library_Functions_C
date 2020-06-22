/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 14:45:00 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/14 10:35:57 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (needle[n] == '\0')
		return (char*)(&(haystack[h]));
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && h + n < len)
		{
			if (needle[n] == '\0')
				return ((char*)(&haystack[h]));
			n++;
		}
		if (needle[n] == '\0')
			return ((char*)(&haystack[h]));
		h++;
	}
	return (0);
}
