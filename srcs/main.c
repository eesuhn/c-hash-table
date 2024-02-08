#include "../incs/hash_table.h"
#include "../incs/ft.h"

int	main(void)
{
	t_ht_table	*ht;

	ht = ht_new();
	ht_insert(ht, "abc", "cat");
	printf("%s\n", ht_search(ht, "abc"));
	// ht_delete(ht, "abc");
	// printf("%s\n", ht_search(ht, "abc"));
	ht_del_table(ht);
	return (0);
}
