## Hash Table in C

#### Features: 
- Collision resolvement with open addressing and double hashing
- Dynamic bucket size with load management

<i>*all without the use of standard library</i>

#### Setting up
1. Run `make` to compile the library.
2. Include `ft_ht.h`, and link the library with `-lft_ht` flag.

#### Methods: 
```c
/**
 * To initialize new hash table.
 * 
 * @return t_ht_table* ht
 */
t_ht_table	*ht_new(void);

/**
 * To insert new item to hash table.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 * @param const char* value
 */
void		ht_insert(t_ht_table *ht, const char *key, const char *value);

/**
 * To search value by key.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 * 
 * @return char* value
 */
char		*ht_search(t_ht_table *ht, const char *key);

/**
 * To delete item from hash table.
 * 
 * @param t_ht_table* ht
 * @param const char* key
 */
void		ht_delete(t_ht_table *ht, const char *key);

/**
 * To delete hash table.
 * 
 * @param t_ht_table* ht
 */
void		ht_del_table(t_ht_table *ht);
```

<i>I sort of like program in C now :)</i>
