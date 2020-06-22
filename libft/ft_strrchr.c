/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:18:09 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/12 14:10:34 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			res = (char*)s + i;
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	return (res);
}
