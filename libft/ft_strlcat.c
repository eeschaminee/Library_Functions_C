/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 16:48:04 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/14 11:37:43 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;
	size_t i;

	len_dst = 0;
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	if (len_dst < (dstsize - 1))
	{
		while (((len_dst + i) < (dstsize - 1)) && src[i] != '\0')
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	if (dstsize > len_dst)
		return (len_dst + len_src);
	return (dstsize + len_src);
}
