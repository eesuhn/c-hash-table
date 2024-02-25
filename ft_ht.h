#ifndef FT_HT_H
# define FT_HT_H

# include <stdlib.h>

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

/**
 * To initialize new hash table.
 * 
 * @return t_ht_table*
 */
t_ht_table	*ht_new(void);

/**
 * To insert new item to hash table.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 * @param const char* value
 */
void	ht_insert(t_ht_table *ht, const char *key, const char *value);

/**
 * To search value by key.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 * 
 * @return char* value
 */
char	*ht_search(t_ht_table *ht, const char *key);

/**
 * To delete item from hash table.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 */
void	ht_delete(t_ht_table *ht, const char *key);

/**
 * To delete hash table.
 * 
 * @param t_ht_table* ht
 */
void	ht_del_table(t_ht_table *ht);

#endif
