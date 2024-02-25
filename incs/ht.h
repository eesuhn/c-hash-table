#ifndef HT_H
# define HT_H

# include <stdlib.h>
# include <stdio.h>

# define HT_INIT_BASE_SIZE 50
# define HT_PRIME_1 257
# define HT_PRIME_2 263

typedef struct s_item
{
	char	*key;
	char	*value;
}	t_ht_item;

typedef struct s_hash_table
{
	int			size;
	int			base_size;
	int			count;
	t_ht_item	**items;
}	t_ht_table;

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
long	ft_pow(int nb, unsigned int pow);
int		ft_is_prime(int nb);
int		ft_next_prime(int nb);

t_ht_item	*ht_new_item(const char *k, const char *v);
t_ht_table	*ht_new_sized(const int base_size);
void		ht_del_item(t_ht_item *i);
void		ht_resize_up(t_ht_table *ht);
void		ht_resize_down(t_ht_table *ht);
int			ht_get_hash(const char *s, const int bucket, const int attempt);

t_ht_table	*ht_new(void);
void		ht_del_table(t_ht_table *ht);
void		ht_insert(t_ht_table *ht, const char *key, const char *value);
char		*ht_search(t_ht_table *ht, const char *key);
void		ht_delete(t_ht_table *ht, const char *key);

#endif
