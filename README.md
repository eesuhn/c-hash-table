## Hash Structure in C

#### Features: 
- Collision resolvement with open addressing and double hashing
- Dynamic bucket size with load management

#### Setting up is easy
1. Create a copy `git clone https://github.com/eesuhn/c-hash-table.git`
2. Navigate to the directory `cd c-hash-table`
3. Run `make` to generate static library `libft_ht.a`

<i>*For update: run `git pull`, and then `make re`</i>

#### Methods (Header file): 
```c
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
```

<i>I sort of like program in C now :)</i>
