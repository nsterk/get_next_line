/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 19:22:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/09 23:18:58 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void		print_error(int fd, char **line)
{
	printf("\e[0;31m");
	if (fd < 0)
		printf("error: fd is negative\n");
	else if (BUFFER_SIZE <= 0)
		printf("error: BUFFER_SIZE <= 0\n");
	else if (!line)
		printf("error: !line\n");
	else
		printf("error encountered during reading or memory allocation\n");
	printf("\e[0m");
}

int				main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 1;
	ret = 1;
	if (argc == 1)
	{
		printf("\e[0;31merror: no argument supplied\e[0m\n");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("\e[0;31merror: failed to open file\e[0m\n");
			return (0);
		}
	}
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			print_error(fd, &line);
			break ;
		}
		printf("%i: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
