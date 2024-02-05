#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>

typedef struct s_item
{
	char	*key;
	char	*value;
}	t_ht_item;

typedef struct s_hash_table
{
	int			size;
	int			count;
	t_ht_item	**items;
}	t_ht_hash_table;

static t_ht_item	*ht_new_item(const char *k, const char *v);

t_ht_hash_table		*ht_new(void);

static void			ht_del_item(t_ht_item *i);

void				ht_del_table(t_ht_hash_table *ht);

#endif
