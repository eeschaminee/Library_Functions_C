/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puthex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:05 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/08 11:19:53 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex(unsigned int i, int low_or_up, t_info *info)
{
	if (i > 15)
	{
		puthex(i / 16, low_or_up, info);
		puthex(i % 16, low_or_up, info);
	}
	else
	{
		if (i <= 9)
			protected_putchar(i + '0', info);
		else
			protected_putchar(i + 55 + low_or_up, info);
	}
}

void	puthex_long(unsigned long i, t_info *info)
{
	if (i > 15)
	{
		puthex_long(i / 16, info);
		puthex_long(i % 16, info);
	}
	else
	{
		if (i <= 9)
			protected_putchar(i + '0', info);
		else
			protected_putchar(i + 55 + 'a' - 'A', info);
	}
}

void	puthex_up(unsigned int i, t_info *info)
{
	puthex(i, 0, info);
}

void	puthex_low(unsigned int i, t_info *info)
{
	puthex(i, 'a' - 'A', info);
}
