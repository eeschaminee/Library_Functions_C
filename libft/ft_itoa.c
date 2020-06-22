/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:13:30 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/14 13:29:45 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_array_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void		ft_calculate(char *str, int len, int n)
{
	int sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_array_len(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	len--;
	ft_calculate(str, len, n);
	return (str);
}
