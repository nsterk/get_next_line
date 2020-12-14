/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 19:22:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/10 18:14:06 by nsterk        ########   odam.nl         */
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
	int		fd3;
	char	*line;
	int		i = 1;
	int		ret1 = 1;
	int		ret2 = 1;
	int		ret3 = 1;

	if (argc == 1)
		fd1 = 0;
	else if (argc < 4)
	{
		printf("\e[0;31merror: supply 3 files\e[0m\n");
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
		fd3 = open(argv[3], O_RDONLY);
		if (fd3 == -1)
		{
			printf("\e[0;31merror: failed to open file 3\e[0m\n");
			return (0);
		}
	}
	while (ret1 || ret2 || ret3)
	{
		if (ret1)
		{
			ret1 = get_next_line(fd1, &line);
			if (ret1 == -1)
			{
				print_error(fd1, &line);
				break ;
			}
			printf("%.2i: \e[0;31m%s\e[0m\n", i, line);
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
			printf("%.2i: \e[0;33m%s\e[0m\n", i, line);
			free(line);
		}
		if (ret3)
		{
			ret3 = get_next_line(fd3, &line);
			if (ret3 == -1)
			{
				print_error(fd3, &line);
				break ;
			}
			printf("%.2i: %s\n", i, line);
			free(line);
		}
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
