#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

#include <unistd.h>
#include <stdlib.h>


size_t	ft_strlen(char const *s);
char	*ft_strnew(size_t size);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		strfind_nl(char const *s);
int		get_next_line(int fd, char **line);

#endif
