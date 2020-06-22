/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_nbr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:16:00 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/08 12:34:33 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_int(t_info *info)
{
	print_signed(info, countnbr, protected_putnbr);
}

void	convert_un_int(t_info *info)
{
	print_unsigned(info, countnbr_unsigned, protected_putnbr_unsigned);
}

void	convert_hex_low(t_info *info)
{
	print_unsigned(info, counthex, puthex_low);
}

void	convert_hex_up(t_info *info)
{
	print_unsigned(info, counthex, puthex_up);
}

void	convert_ptr(t_info *info)
{
	print_pointer(info);
}
