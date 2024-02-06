#include "../incs/ft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(src);
	dup = (char *) malloc(size + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
