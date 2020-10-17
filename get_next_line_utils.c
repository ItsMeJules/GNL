#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (!(dup = ft_strnew(i)))
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = 0;
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (!s || start > s_len)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
		i++;
	if (!(cpy = ft_strnew(i)))
		return (NULL);
	i = -1;
	s += start;
	while (++i < len && s[i])
		cpy[i] = s[i];
	cpy[i] = 0;
	return (cpy);
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

int		strfind_nl(char const *s, int zero)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	if (zero && !s[i])
		return (i);
	return (-1);
}
