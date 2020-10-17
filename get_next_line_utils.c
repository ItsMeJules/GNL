#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if (!(new = malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < size)
		new[i] = 0;
	return (new);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;
	
	if (!(dup = malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < n)
		dup[i] = s[i];
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(new = malloc((i + j + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = 0;
	return (new);
}

int		strfind_nl(char const *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n' || s[i] == 0)
			return (i);
	}
	return (-1);
}
