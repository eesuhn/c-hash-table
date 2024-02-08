#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <stdio.h>

# define HT_PRIME_1 257
# define HT_PRIME_2 263

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *src);

int		ft_strcmp(const char *s1, const char *s2);

void	*ft_calloc(size_t count, size_t size);

long	ft_pow(int nb, unsigned int pow);

int		ft_is_prime(int nb);

int		ft_next_prime(int nb);

#endif
