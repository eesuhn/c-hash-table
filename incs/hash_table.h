#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include <stdio.h>

# include "ht.h"

void		ht_insert(t_ht_table *ht, const char *key, const char *value);

char		*ht_search(t_ht_table *ht, const char *key);

void		ht_delete(t_ht_table *ht, const char *key);

#endif
