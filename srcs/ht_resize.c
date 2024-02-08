#include "../incs/hash_table.h"
#include "../incs/ft.h"

static t_ht_item	g_ht_deleted_item = {NULL, NULL};

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

void	ht_resize_up(t_ht_table *ht)
{
	int	new_size;

	new_size = ht->base_size * 2;
	ht_resize(ht, new_size);
}

void	ht_resize_down(t_ht_table *ht)
{
	int	new_size;

	new_size = ht->base_size / 2;
	ht_resize(ht, new_size);
}
