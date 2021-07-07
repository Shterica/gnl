#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int i;
	int j;
	int k;
	int fd;
	int fd2;
	int fd3;
	char *str = NULL;
	char *str2 = NULL;
	char *str3 = NULL;


	fd = open("./gnlTester/files/41_no_nl", O_RDONLY);
	fd2 = open("./gnlTester/files/42_with_nl", O_RDONLY);
	fd3 = open("./gnlTester/files/multiple_line_with_nl", O_RDONLY);
	
	//printf("%d\n", fd);
	//printf("%d\n", fd2);
	//printf("%d\n", fd3);
	//if (fd < 0)
	//{
	//	printf("VSE PLOHO!\n");
	//	exit(1);
	//}
	 //printf("test: %d: %s\n", fd, FILE_FILE);
	//if ((i = get_next_line(fd, &str)) > 0)
	//{
	//	printf("%s\n", str);
	//	free(str);
	//	str = NULL;
	//	// printf("%d\n", get_next_line(fd, &str));
	//}
//	if ((j = get_next_line(fd2, &str2)) > 0)
	//{
		//printf("%s\n", str2);
		//free(str2);
		//str2 = NULL;
	//}
	//if ((k = get_next_line(fd3, &str3)) > 0)
	//{
		//printf("%s\n", str3);
		//free(str3);
		//str3 = NULL;
//	}
	while ((i = get_next_line(fd, &str)) >= 0)
	{
		printf("%d: %s\n", i, str);
		free(str);
		if (i == 0)
			break ;
		str = NULL;
	}
	while ((j = get_next_line(fd2, &str2)) >= 0)
	{
		printf("%d: %s\n", j, str2);
		free(str2);
		if (j == 0)
			break ;
		str2 = NULL;
	}
	while ((k = get_next_line(fd3, &str3)) >= 0)
	{
		printf("%d: %s\n", k, str3);
		free(str3);
		if (k == 0)
			break ;
		str3 = NULL;
	}
	/*if ((i = get_next_line(fd, &str)) == 0)
	{
		printf("%d: %s\n", i, str);
		free(str);
		str = NULL;
	}*/
	//if ((j = get_next_line(fd2, &str2)) > 0)
	//{
	//	printf("%s\n", str2);
		//free(str2);
		//str2 = NULL;
	//}
	//if ((j = get_next_line(fd2, &str2)) > 0)
	//{
	//	printf("%s\n", str2);
	//	free(str2);
		//str2 = NULL;
	//}
	// printf("%d\n", i);
	return (0);
}
