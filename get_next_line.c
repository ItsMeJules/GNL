#include "get_next_line.h"


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
	
	pos = strfind_nl(content[fd]);
	if (content[fd][pos] == '\n')
	{
		*line = ft_strndup(content[fd], pos + 1);
		tmp = ft_strndup(&content[fd][pos + 1], ft_strlen(&content[fd][pos]));
		free(content[fd]);
		content[fd] = tmp;
		if (content[fd] == 0)
			free_strs(&content[fd]);
	}
	else if (content[fd][0] == 0)
	{
		if (ret == BUFFER_SIZE)
		{
			get_next_line(fd, line);
			return ;
		}
		*line = ft_strndup(content[fd], ft_strlen(content[fd]));
		free_strs(&content[fd]);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*content[300];
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (content[fd] == NULL)
			content[fd] = ft_strnew(1);
		str = ft_strjoin(content[fd], buf);
		free(content[fd]);
		content[fd] = str;
		if (strfind_nl(content[fd]) != -1)
			break;
	}
	if (ret < 0)
		return (-1);
	else if (ret >= 0 && content[fd] != NULL && content[fd][0] != 0)
	{
		extract_line(fd, line, content, ret);
		return (1);
	}
	return (0);
}
