/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpeyron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:23:26 by jpeyron           #+#    #+#             */
/*   Updated: 2020/11/20 21:27:59 by jpeyron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		extract_line(int fd, char **line, char **content, int ret)
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
			return (get_next_line(fd, line));
		*line = ft_strdup(content[fd]);
		free_strs(&content[fd]);
		return (0);
	}
	return (1);
}

int		handle_return(char **line, char **content, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!content[fd] || !content[fd][0]))
	{
		if (!*line)
			*line = ft_strnew(1);
		return (0);
	}
	return (extract_line(fd, line, content, ret));
}

int		get_next_line(int fd, char **line)
{
	static char	*content[300];
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
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
			break ;
	}
	return (handle_return(line, content, ret, fd));
}
