/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 10:49:42 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/15 15:22:43 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_info *info)
{
	char	c;
	int		precision;

	c = (char)va_arg(*info->args, int);
	print_width(info, 1, 0);
	precision = calculate_precision(info);
	print_precision(info, precision, 1);
	protected_putchar(c, info);
	print_width(info, 1, 1);
}

void	convert_prec(t_info *info)
{
	int	precision;

	print_width(info, 1, 0);
	precision = calculate_precision(info);
	print_precision(info, precision, 1);
	protected_putchar('%', info);
	print_width(info, 1, 1);
}

void	convert_str(t_info *info)
{
	char	*str;
	int		len;

	str = va_arg(*info->args, char *);
	if (info->precision == 0 && info->has_precision_flag)
		str = "";
	else if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (info->has_precision_flag && info->precision < len)
		len = info->precision;
	print_width(info, len, 0);
	protected_putstr(str, len, info);
	print_width(info, len, 1);
}
