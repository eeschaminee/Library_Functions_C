/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 11:29:09 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/15 15:26:55 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


void		call_specifier(t_info *info)
{
	if (info->specifier == 'c')
		convert_char(info);
	else if (info->specifier == 's')
		convert_str(info);
	else if (info->specifier == 'p')
		convert_ptr(info);
	else if (info->specifier == 'd' || info->specifier == 'i')
		convert_int(info);
	else if (info->specifier == 'u')
		convert_un_int(info);
	else if (info->specifier == 'x')
		convert_hex_low(info);
	else if (info->specifier == 'X')
		convert_hex_up(info);
	else if (info->specifier == '%')
		convert_prec(info);
}

void		printf_loop(const char *fmt, t_info *info, int *i)
{
	if (fmt[*i] != '%')
	{
		protected_putchar(fmt[*i], info);
		(*i)++;
	}
	else
	{
		(*i)++;
		if (fmt[*i] != '\0')
			parse_fmt(fmt, info, i);
		else
			info->len_printed = -1;
	}
}

int			ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	ap;
	t_info	info;

	i = 0;
	va_start(ap, fmt);
	info.args = &ap;
	info.len_printed = 0;
	while (fmt[i] != '\0')
	{
		printf_loop(fmt, &info, &i);
	}
	va_end(ap);
	return (info.len_printed);
}
