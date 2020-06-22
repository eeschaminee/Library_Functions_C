/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:37:27 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 15:19:22 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_parse(int i, const char *str, int sign)
{
	long int	long_check;
	long int	res;

	res = 0;
	long_check = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (long_check <= res)
		{
			long_check = res;
			res = res * 10 + str[i] - '0';
			i++;
		}
		else
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
	}
	return (sign * res);
}

int			ft_atoi(const char *str)
{
	int			sign;
	long int	res;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = ft_parse(i, str, sign);
	return (int)(res);
}
