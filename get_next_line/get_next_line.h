/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:45:06 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/20 17:08:06 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# ifndef FD_SIZE
#  define FD_SIZE 1000
# endif
# include <stddef.h>

int			get_next_line(int fd, char **line);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s1, size_t size);
int			ft_char_position(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_strnappend(char **s1, char const *s2, int n2);

#endif
