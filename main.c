#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int i;
	int fd[ac - 1];
	char *str = NULL;
	int	out;
	int	exit;

	i = 0;
	while (i++ < ac)
		fd[i] = open(av[i], O_RDONLY);
	
	while (1)
	{
		i = 1;
		exit = 1;
		while (i < ac)
		{
			out = get_next_line(fd[i], &str);
			printf("fd = %d: %s\n", fd[i], str);
			free(str);
			if (out > 0)
				exit = 0;
			i += 1;
		}
		if (exit)
			break ;
	}
	return (0);
}
