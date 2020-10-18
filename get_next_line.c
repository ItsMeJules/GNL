#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	free_strs(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

void	extract_line(int fd, char **line, char **content, int ret)
{
	int		pos;
	char	*tmp;
	
	pos = strfind_nl(content[fd], 1);
	if (content[fd][pos] == '\n')
	{
		*line = ft_substr(content[fd], 0, pos);
		tmp = ft_strdup(content[fd] + pos + 1);
		free(content[fd]);
		content[fd] = tmp;
		if (!content[fd][0])
			free_strs(&content[fd]);
	}
	else if (content[fd][pos] == 0)
	{
		if (ret == BUFFER_SIZE)
		{
			get_next_line(fd, line);
			return ;
		}
		*line = ft_strdup(content[fd]);
		free_strs(&content[fd]);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*content[300];
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!content[fd])
		content[fd] = ft_strnew(1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		str = ft_strjoin(content[fd], buf);
		free(content[fd]);
		content[fd] = str;
		if (strfind_nl(content[fd], 0) != -1)
			break;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!content[fd] || !content[fd][0]))
		return (0);
	extract_line(fd, line, content, ret);
	return (1);
}

int main()
{
	int 	fd = open("1.txt", O_RDONLY);
	char	*line;

	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	return (0);
}
