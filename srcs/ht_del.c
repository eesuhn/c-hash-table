#include "../incs/ft.h"
#include "../incs/ht.h"

void	ht_del_item(t_ht_item *i)
{
	if (i->key == NULL && i->value == NULL)
		return ;
	free(i->key);
	free(i->value);
	free(i);
}

/**
 * To delete hash table.
 * 
 * @param t_ht_table* ht
 */
void	ht_del_table(t_ht_table *ht)
{
	int	i;

	i = -1;
	while (++i < ht->size)
		if (ht->items[i] != NULL)
			ht_del_item(ht->items[i]);
	free(ht->items);
	free(ht);
}
