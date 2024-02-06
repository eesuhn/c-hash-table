#include "../incs/hash_table.h"
#include "../incs/ft.h"

int	main(void)
{
	t_ht_hash_table	*ht;

	ht = ht_new();
	ht_del_table(ht);
	return (0);
}
