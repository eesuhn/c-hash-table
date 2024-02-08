#include "../incs/hash_table.h"
#include "../incs/ft.h"
#include "../incs/prime.h"

static t_ht_item	g_ht_deleted_item = {NULL, NULL};

static t_ht_item	*ht_new_item(const char *k, const char *v)
{
	t_ht_item	*i;

	i = (t_ht_item *) malloc(sizeof(t_ht_item));
	i->key = ft_strdup(k);
	i->value = ft_strdup(v);
	return (i);
}

t_ht_table	*ht_new(void)
{
	t_ht_table	*ht;

	ht = (t_ht_table *) malloc(sizeof(t_ht_table));
	ht->size = 1000;
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

void	ht_del_table(t_ht_table *ht)
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

void	ht_insert(t_ht_table *ht, const char *key, const char *value)
{
	t_ht_item	*item;
	int			index;
	t_ht_item	*cur_item;
	int			i;

	item = ht_new_item(key, value);
	index = ht_get_hash(item->key, ht->size, 0);
	cur_item = ht->items[index];
	i = 1;
	while (cur_item != NULL && cur_item != &g_ht_deleted_item)
	{
		if (!ft_strcmp(cur_item->key, key))
		{
			ht_del_item(cur_item);
			ht->items[index] = item;
			return ;
		}
		index = ht_get_hash(item->key, ht->size, i);
		cur_item = ht->items[index];
		i++;
	}
	ht->items[index] = item;
	ht->count++;
}

char	*ht_search(t_ht_table *ht, const char *key)
{
	int			index;
	t_ht_item	*item;
	int			i;

	index = ht_get_hash(key, ht->size, 0);
	item = ht->items[index];
	i = 1;
	while (item != NULL)
	{
		if (!ft_strcmp(item->key, key) && item != &g_ht_deleted_item)
			return (item->value);
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	return (NULL);
}

void	ht_delete(t_ht_table *ht, const char *key)
{
	int			index;
	t_ht_item	*item;
	int			i;

	index = ht_get_hash(key, ht->size, 0);
	item = ht->items[index];
	i = 1;
	while (item != NULL)
	{
		if (item != &g_ht_deleted_item)
		{
			if (!ft_strcmp(item->key, key))
			{
				ht_del_item(item);
				ht->items[index] = &g_ht_deleted_item;
			}
		}
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	ht->count--;
}
