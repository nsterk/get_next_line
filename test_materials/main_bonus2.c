/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 19:22:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/13 11:32:49 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	int		fd1;
	int		fd2;
	char	*line;
	int		i = 1;
	int		ret1 = 1;
	int		ret2 = 1;

	if (argc == 1)
		fd1 = 0;
	else if (argc < 3)
	{
		printf("\e[0;31merror: supply 2 files\e[0m\n");
		return (0);
	}
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
		{
			printf("\e[0;31merror: failed to open file 1\e[0m\n");
			return (0);
		}
		fd2 = open(argv[2], O_RDONLY);
		if (fd2 == -1)
		{
			printf("\e[0;31merror: failed to open file 2\e[0m\n");
			return (0);
		}
	}
	while (ret1 || ret2)
	{
		if (ret1)
		{
			ret1 = get_next_line(fd1, &line);
			if (ret1 == -1)
			{
				print_error(fd1, &line);
				break ;
			}
			printf("%.2i: \e[0;32m%s\e[0m\n", i, line);
			free(line);
		}
		if (ret2)
		{
			ret2 = get_next_line(fd2, &line);
			if (ret2 == -1)
			{
				print_error(fd2, &line);
				break ;
			}
			printf("%.2i: %s\n", i, line);
			free(line);
		}
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
