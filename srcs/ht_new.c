#include "../incs/hash_table.h"
#include "../incs/ft.h"

t_ht_item	*ht_new_item(const char *k, const char *v)
{
	t_ht_item	*i;

	i = (t_ht_item *) malloc(sizeof(t_ht_item));
	i->key = ft_strdup(k);
	i->value = ft_strdup(v);
	return (i);
}

t_ht_table	*ht_new_sized(const int base_size)
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
