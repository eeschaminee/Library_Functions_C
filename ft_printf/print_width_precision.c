/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_width_precision.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 12:23:11 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/08 12:23:27 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_info *info, int len, int after)
{
	int	left_over;
	int	length;
	int	i;

	i = 0;
	if (!info->width || info->minus_flag != after
		|| (info->zeroes_flag && !info->precision && !info->minus_flag))
		return ;
	if (len > info->precision || (len < info->precision &&
			info->specifier == 's'))
		length = len;
	else
		length = info->precision;
	left_over = info->width - length - info->is_negative_flag;
	while (i < left_over)
	{
		protected_putchar(' ', info);
		i++;
	}
}

void	print_precision(t_info *info, int precision, int len)
{
	while (precision > len)
	{
		protected_putchar('0', info);
		precision--;
	}
}
