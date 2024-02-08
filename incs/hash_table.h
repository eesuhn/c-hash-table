#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include <stdio.h>

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
}	t_ht_table;

t_ht_table	*ht_new(void);

void		ht_del_table(t_ht_table *ht);

void		ht_insert(t_ht_table *ht, const char *key, const char *value);

char		*ht_search(t_ht_table *ht, const char *key);

void		ht_delete(t_ht_table *ht, const char *key);

#endif
