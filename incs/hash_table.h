#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include <stdio.h>

# define HT_INIT_BASE_SIZE 50

typedef struct s_item
{
	char	*key;
	char	*value;
}	t_ht_item;

typedef struct s_hash_table
{
	int			size;
	int			base_size;
	int			count;
	t_ht_item	**items;
}	t_ht_table;

t_ht_item	*ht_new_item(const char *k, const char *v);

t_ht_table	*ht_new_sized(const int base_size);

t_ht_table	*ht_new(void);

void		ht_del_item(t_ht_item *i);

void		ht_del_table(t_ht_table *ht);

void		ht_resize_up(t_ht_table *ht);

void		ht_resize_down(t_ht_table *ht);

int			ht_get_hash(const char *s, const int bucket, const int attempt);

void		ht_insert(t_ht_table *ht, const char *key, const char *value);

char		*ht_search(t_ht_table *ht, const char *key);

void		ht_delete(t_ht_table *ht, const char *key);

#endif
