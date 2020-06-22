/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:57:10 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/08 11:21:40 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	protected_putnbr(int n, t_info *info)
{
	if (n == -2147483648)
	{
		protected_putchar('2', info);
		n = 147483648;
	}
	if (n >= 10)
	{
		protected_putnbr(n / 10, info);
		protected_putnbr(n % 10, info);
	}
	else
		protected_putchar(n + '0', info);
}

void	protected_putnbr_unsigned(unsigned int n, t_info *info)
{
	if (n >= 10)
	{
		protected_putnbr_unsigned(n / 10, info);
		protected_putnbr_unsigned(n % 10, info);
	}
	else
		protected_putchar(n + '0', info);
}
