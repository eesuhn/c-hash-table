#include "../incs/hash_table.h"
#include "../incs/ft.h"
#include "../incs/prime.h"

static t_ht_item	*ht_new_item(const char *k, const char *v)
{
	t_ht_item	*i;

	i = (t_ht_item *) malloc(sizeof(t_ht_item));
	i->key = ft_strdup(k);
	i->value = ft_strdup(v);
	return (i);
}

t_ht_hash_table	*ht_new(void)
{
	t_ht_hash_table	*ht;

	ht = (t_ht_hash_table *) malloc(sizeof(t_ht_hash_table));
	ht->size = 100;
	ht->count = 0;
	ht->items = ft_calloc((size_t)ht->size, sizeof(t_ht_item *));
	return (ht);
}

static void	ht_del_item(t_ht_item *i)
{
	free(i->key);
	free(i->value);
	free(i);
}

void	ht_del_table(t_ht_hash_table *ht)
{
	int			i;

	i = -1;
	while (++i < ht->size)
	{
		if (ht->items[i] != NULL)
			ht_del_item(ht->items[i]);
	}
	free(ht->items);
	free(ht);
}

static int	ht_hash(const char *s, const int a, const int m)
{
	long	hash;
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s);
	hash = 0;
	i = -1;
	while ((unsigned int)++i < s_len)
		hash += (long)ft_pow(a, s_len - (i + 1)) * (int)s[i];
	hash = hash % m;
	return ((int)hash);
}

static int	ht_get_hash(const char *s, const int num_buckets, const int attempt)
{
	int	hash_a;
	int	hash_b;

	hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
	hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
	return ((hash_a + (attempt * (hash_b + 1))) % num_buckets);
}
