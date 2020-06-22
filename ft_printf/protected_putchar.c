/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   protected_putchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:49:42 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/07 12:38:01 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	protected_putchar(char c, t_info *info)
{
	int return_write;

	return_write = write(1, &c, 1);
	if (return_write != -1 && info->len_printed != -1)
		info->len_printed += 1;
	else
		info->len_printed = -1;
}

void	protected_putstr(char *c, int len, t_info *info)
{
	int return_write;

	return_write = write(1, c, len);
	if (return_write != -1 && info->len_printed != -1)
		info->len_printed += len;
	else
		info->len_printed = -1;
}