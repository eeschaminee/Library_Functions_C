/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:44:13 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/21 10:47:22 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int	remove_first_n_characters(char *s, int n)
{
	int len;

	len = ft_strlen(s);
	if (n >= len)
	{
		s[0] = '\0';
		return (0);
	}
	ft_memmove(s, s + n, len - n);
	s[len - n] = '\0';
	return (len - n);
}

static int	free_result(char **result)
{
	free(*result);
	return (-1);
}

static int	get_from_mem(char *mem, char **result)
{
	int loc;

	if (ft_strlen(mem))
	{
		loc = ft_char_position(mem, '\n');
		if (loc < 0)
		{
			if (!ft_strnappend(result, mem, ft_strlen(mem)))
				return (free_result(result));
			mem[0] = '\0';
			return (0);
		}
		else if (loc > 0)
		{
			if (!ft_strnappend(result, mem, loc))
				return (free_result(result));
		}
		remove_first_n_characters(mem, loc + 1);
		return (1);
	}
	return (0);
}

static int	check_and_initialize(int fd,
	char **fd_mem, char **line, char **result)
{
	if (fd < 0 || read(fd, 0, 0) == -1 || line == 0 || fd >= FD_SIZE)
		return (0);
	if (fd_mem[fd] == 0)
	{
		fd_mem[fd] = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (fd_mem[fd] == 0)
			return (0);
		fd_mem[fd][0] = '\0';
	}
	*result = ft_strdup("", 0);
	if (!*result)
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_mem[FD_SIZE];
	int			size;
	char		*result;
	int			found;

	if (!check_and_initialize(fd, fd_mem, line, &result))
		return (-1);
	found = get_from_mem(fd_mem[fd], &result);
	while (!found)
	{
		size = read(fd, fd_mem[fd], BUFFER_SIZE);
		fd_mem[fd][size] = '\0';
		found = get_from_mem(fd_mem[fd], &result);
		if (found == -1)
			return (found);
		if (!size)
			break ;
	}
	if (!found)
	{
		free(fd_mem[fd]);
		fd_mem[fd] = 0;
	}
	*line = result;
	return (found);
}
