#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#include <unistd.h>
#include <stdlib.h>


char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		strfind_nl(char const *s, int zero);
int		get_next_line(int fd, char **line);

#endif

