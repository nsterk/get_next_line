/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 21:04:10 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/13 11:57:35 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2, size_t len_s2);

#endif
