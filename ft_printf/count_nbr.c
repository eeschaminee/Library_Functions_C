/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_nbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:19:23 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/08 13:26:55 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		countnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count++;
		n = 147483648;
	}
	if (n >= 10)
	{
		count += countnbr(n / 10);
		count += countnbr(n % 10);
	}
	else
		return (1);
	return (count);
}

int		countnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += countnbr(n / 10);
		count += countnbr(n % 10);
	}
	else
		return (1);
	return (count);
}

int		counthex(unsigned int i)
{
	int	count;

	count = 0;
	if (i > 15)
	{
		count += counthex(i / 16);
		count += counthex(i % 16);
	}
	else
		return (1);
	return (count);
}

int		counthex_long(unsigned long i)
{
	int	count;

	count = 0;
	if (i > 15)
	{
		count += counthex_long(i / 16);
		count += counthex_long(i % 16);
	}
	else
		return (1);
	return (count);
}
