#include "../incs/hash_table.h"
#include "../incs/ft.h"

static t_ht_item	g_ht_deleted_item = {NULL, NULL};

void	ht_insert(t_ht_table *ht, const char *key, const char *value)
{
	t_ht_item	*item;
	int			index;
	t_ht_item	*cur_item;
	int			i;

	if ((ht->count * 100 / ht->size) > 70)
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
