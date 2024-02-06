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

t_ht_hash_table		*ht_new(void);

void				ht_del_table(t_ht_hash_table *ht);

int					ht_hash(const char *s, const int a, const int m);

#endif
