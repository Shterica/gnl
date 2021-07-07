#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int i;
	int fd[ac];
	char *str = NULL;
	int	out;
	int	exit;

	i = 0;
	while (++i < ac)
	{
		fd[i] = open(av[i], O_RDONLY);
		if(fd[i] == -1)
			printf("Cannot open %s\n", av[i]);
	}
	fd[0] = -5;
	while (1)
	{
		i = 1;
		exit = 1;
		while (i < ac)
		{
			str = get_next_line(fd[i]);
			if (str)
			{
				exit = 0;
				printf("fd = %d: %s\n", fd[i], str);
			}
			free(str);
			i += 1;
		}
		if (exit)
			break ;
	}
	i = 0;
	while (++i < ac)
		if(fd[i] != -1)
			close(fd[i]);
	return (0);
}
