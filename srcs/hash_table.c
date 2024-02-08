#include "../incs/hash_table.h"
#include "../incs/ft.h"

static t_ht_item	g_ht_deleted_item = {NULL, NULL};

static t_ht_item	*ht_new_item(const char *k, const char *v)
{
	t_ht_item	*i;

	i = (t_ht_item *) malloc(sizeof(t_ht_item));
	i->key = ft_strdup(k);
	i->value = ft_strdup(v);
	return (i);
}

static t_ht_table	*ht_new_sized(const int base_size)
{
	t_ht_table	*ht;

	ht = (t_ht_table *) malloc(sizeof(t_ht_table));
	if (ht == NULL)
		return (NULL);
	ht->size = ft_next_prime(base_size);
	ht->base_size = base_size;
	ht->count = 0;
	ht->items = ft_calloc((size_t)ht->size, sizeof(t_ht_item *));
	if (ht->items == NULL)
		return (NULL);
	return (ht);
}

t_ht_table	*ht_new(void)
{
	return (ht_new_sized(HT_INIT_BASE_SIZE));
}

static void	ht_resize(t_ht_table *ht, const int base_size)
{
	t_ht_table	*new_ht;
	int			i;
	t_ht_item	*item;
	int			tmp_size;
	t_ht_item	**tmp_items;

	if (base_size < HT_INIT_BASE_SIZE)
		return ;
	new_ht = ht_new_sized(base_size);
	i = -1;
	while (++i < ht->size)
	{
		item = ht->items[i];
		if (item != NULL && item != &g_ht_deleted_item)
			ht_insert(new_ht, item->key, item->value);
	}
	ht->base_size = new_ht->base_size;
	ht->count = new_ht->count;
	tmp_size = ht->size;
	ht->size = new_ht->size;
	new_ht->size = tmp_size;
	tmp_items = ht->items;
	ht->items = new_ht->items;
	new_ht->items = tmp_items;
	ht_del_table(new_ht);
}

static void	ht_resize_up(t_ht_table *ht)
{
	int	new_size;

	new_size = ht->base_size * 2;
	ht_resize(ht, new_size);
}

static void	ht_resize_down(t_ht_table *ht)
{
	int	new_size;

	new_size = ht->base_size / 2;
	ht_resize(ht, new_size);
}

static void	ht_del_item(t_ht_item *i)
{
	free(i->key);
	free(i->value);
	free(i);
}

void	ht_del_table(t_ht_table *ht)
{
	int	i;

	i = -1;
	while (++i < ht->size)
		if (ht->items[i] != NULL && ht->items[i] != &g_ht_deleted_item)
			ht_del_item(ht->items[i]);
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
	int			load;

	load = ht->count * 100 / ht->size;
	if (load > 70)
		ht_resize_up(ht);
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
		if (!ft_strcmp(item->key, key))
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
	int			load;

	load = ht->count * 100 / ht->size;
	if (load < 10)
		ht_resize_down(ht);
	index = ht_get_hash(key, ht->size, 0);
	item = ht->items[index];
	i = 1;
	while (item != NULL)
	{
		if (item != &g_ht_deleted_item && !ft_strcmp(item->key, key))
		{
			ht_del_item(item);
			ht->items[index] = &g_ht_deleted_item;
			break ;
		}
		index = ht_get_hash(key, ht->size, i);
		item = ht->items[index];
		i++;
	}
	ht->count--;
}
