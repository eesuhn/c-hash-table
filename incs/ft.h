#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *src);

void	*ft_calloc(size_t count, size_t size);

long	ft_pow(int nb, unsigned int pow);

#endif