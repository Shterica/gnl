#include "get_next_line_bonus.h"

static char	*ft_init(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

static char	*appendline(char **s, int rd)
{
	char	*tmp;
	int		i;
	char	*line;

	if (rd < 0 && ft_strlen(*s) == 0)
		return (NULL);
	i = 0;
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	line = ft_substr(*s, 0, i + 1);
	if ((*s)[i] == '\n')
		tmp = ft_strdup(&((*s)[i + 1]));
	else
		tmp = NULL;
	free (*s);
	*s = tmp;
	if (rd > 0 || i > 0)
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*s[FD_SIZE];
	char			buff[BUFFER_SIZE + 1];
	char			*temp;
	int				rd;

	rd = 1;
	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!s[fd])
		s[fd] = ft_init();
	while (ft_strchr(s[fd], '\n') == NULL)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		temp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = temp;
	}
	return (appendline(&s[fd], rd));
}
