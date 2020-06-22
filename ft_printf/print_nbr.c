/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_nbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:15:51 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/15 14:44:13 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calculate_precision(t_info *info)
{
	int	precision;

	precision = 0;
	if (info->zeroes_flag && !(info->precision && info->has_precision_flag) && !info->minus_flag)
	{
		if (info->is_negative_flag)
			precision = info->width - 1;
		else
			precision = info->width;
	}
	else
		precision = info->precision;
	return (precision);
}

void	print_signed(t_info *info, int count_number(int),
	void print_number(int, t_info*))
{
	int	len;
	int	precision;
	int	i;

	i = (int)va_arg(*info->args, int);
	if (i < 0)
	{
		info->is_negative_flag = 1;
		i = i * -1;
	}
	len = count_number(i);
	if (i == 0 && info->precision == 0 && info->has_precision_flag)
		len = 0;
	else if (i == 0 && info->precision == 0 && !info->has_precision_flag)
		len = 1;
	print_width(info, len, 0);
	if (info->is_negative_flag)
		protected_putchar('-', info);
	precision = calculate_precision(info);
	print_precision(info, precision, len);
	if (!(i == 0 && info->precision == 0 && info->has_precision_flag))
		print_number(i, info);
	print_width(info, len, 1);
}

void	print_unsigned(t_info *info, int count_number(unsigned int),
	void print_number(unsigned int, t_info*))
{
	int				len;
	int				precision;
	unsigned int	i;

	i = (unsigned int)va_arg(*info->args, unsigned int);
	len = count_number(i);
	if (i == 0 && info->precision == 0)
		len = 0;
	if (i == 0 && info->precision == 0 && !info->has_precision_flag)
		len = 1;
	print_width(info, len, 0);
	precision = calculate_precision(info);
	print_precision(info, precision, len);
	if (!(i == 0 && info->precision == 0 && info->has_precision_flag))
		print_number(i, info);
	print_width(info, len, 1);
}

void	print_pointer(t_info *info)
{
	int				len;
	int				precision;
	unsigned long	i;

	i = (unsigned long)va_arg(*info->args, unsigned long);
	if (i != 0)
	{
		len = counthex_long(i);
		len += 2;
	}
	else if (i == 0 && info->has_precision_flag)
		len = 2;
	else
		len = 3;
	print_width(info, len, 0);
	if (info->width)
		protected_putstr("0x", 2, info);
	precision = calculate_precision(info);
	print_precision(info, precision, len);
	if (!info->width)
		protected_putstr("0x", 2, info);
	if (!(i == 0 && info->precision == 0 && info->has_precision_flag))
		puthex_long(i, info);
	print_width(info, len, 1);
}
