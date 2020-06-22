/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:45:41 by eschamin       #+#    #+#                */
/*   Updated: 2020/01/15 13:43:39 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_info
{
	va_list		*args;
	char		specifier;
	int			minus_flag;
	int			zeroes_flag;
	int			is_negative_flag;
	int			has_precision_flag;
	int			precision;
	int			width;
	int			len_printed;
}				t_info;

int				ft_printf(const char *fmt, ...);
void			call_specifier(t_info *info);

/*
** parse format
*/
void			parse_fmt(const char *fmt, t_info *info, int *i);

/*
** convert char and nbr
*/
void			convert_char(t_info *info);
void			convert_str(t_info *info);
void			convert_prec(t_info *info);
void			convert_int(t_info *info);
void			convert_un_int(t_info *info);
void			convert_hex_low(t_info *info);
void			convert_hex_up(t_info *info);
void			convert_ptr(t_info *info);

/*
** count nbr
*/
int				counthex(unsigned int i);
int				counthex_long(unsigned long i);
int				countnbr(int n);
int				countnbr_unsigned(unsigned int n);

/*
** functions to print the argument with the right width and precision
*/
int				calculate_precision(t_info *info);
void			print_signed(t_info *info, int count_number(int),
					void print_number(int, t_info*));
void			print_unsigned(t_info *info, int count_number(unsigned
					int), void print_number(unsigned int, t_info*));
void			print_pointer(t_info *info);
void			print_width(t_info *info, int width, int after);
void			print_precision(t_info *info, int precision, int len);

/*
** functions to put hex
*/
void			puthex(unsigned int i, int low_or_up, t_info *info);
void			puthex_long(unsigned long i, t_info *info);
void			puthex_up(unsigned int i, t_info *info);
void			puthex_low(unsigned int i, t_info *info);

/*
** all functions to write something to stdout
*/
void			protected_putchar(char c, t_info *info);
void			protected_putstr(char *c, int len, t_info *info);
void			protected_putnbr(int n, t_info *info);
void			protected_putnbr_unsigned(unsigned int n, t_info *info);

/*
** utils
*/
size_t			ft_strlen(const char *s);

#endif
