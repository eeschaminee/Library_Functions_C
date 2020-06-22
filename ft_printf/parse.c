#include "ft_printf.h"

static int		ft_parse_num_flag(int *i, const char *fmt)
{
	long int	res;

	res = 0;
	while (fmt[*i] != '\0' && fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		res = res * 10 + fmt[*i] - '0';
		(*i)++;
	}
	return (res);
}

static void		set_flags(const char *fmt, t_info *info, int *i)
{
	info->specifier = 0;
	info->minus_flag = 0;
	info->zeroes_flag = 0;
	info->is_negative_flag = 0;
	info->has_precision_flag = 0;
	info->precision = 0;
	info->width = 0;
	if (fmt[(*i)] == '-')
	{
		info->minus_flag = 1;
		(*i)++;
	}
	if (fmt[(*i)] == '0')
	{
		info->zeroes_flag = 1;
		(*i)++;
	}
	if (fmt[(*i)] == '-')
	{
		info->minus_flag = 1;
		(*i)++;
	}
}

static void	set_width(const char *fmt, t_info *info, int *i)
{
	if (fmt[*i] == '*')
	{
		info->width = (int)va_arg(*info->args, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->minus_flag = 1;
			info->zeroes_flag = 0;
		}
		(*i)++;
	}
	else
		info->width = ft_parse_num_flag(&(*i), fmt);
}

static void	set_precision(const char *fmt, t_info *info, int *i)
{
	if (fmt[*i] == '.')
	{
		(*i)++;
		info->precision = ft_parse_num_flag(&(*i), fmt);
		info->has_precision_flag = 1;
	}
	if (fmt[*i] == '*')
	{
		info->precision = (int)va_arg(*info->args, int);
		if (info->precision < 0)
		{
			info->precision = 0;
			info->has_precision_flag = 0;
		}
		(*i)++;
	}
}

static int	set_specifiers(const char *fmt, t_info *info, int *i)
{
	char	*supported_specifiers;
	int		is;

	supported_specifiers = "cspdiuxX%";
	is = 0;
	while (supported_specifiers[is] != '\0')
	{
		if (fmt[(*i)] == supported_specifiers[is])
		{
			info->specifier = fmt[(*i)];
			break ;
		}
		is++;
	}
	if (info->specifier)
	{
		call_specifier(info);
		(*i)++;
		return (1);
	}
	return (0);
}


void			parse_fmt(const char *fmt, t_info *info, int *i)
{
	int orig_i;

	orig_i = *i;
	set_flags(fmt, info, i);
	set_width(fmt, info, i);
	set_precision(fmt, info, i);
	if (!set_specifiers(fmt, info, i))
		*i = orig_i;
}
