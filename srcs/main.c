#include "../incs/hash_table.h"
#include "../incs/ft.h"

int	main(void)
{
	t_ht_table	*ht;
	char		*str;

	ht = ht_new();
	ht_insert(ht, "abc123", "Value");
	str = ht_search(ht, "abc123");
	printf("%s\n", str);
	ht_delete(ht, "abc123");
	if (ht_search(ht, "abc123") == NULL)
		printf("Deleted\n");
	ht_del_table(ht);
	return (0);
}
