#include "../incs/ft.h"
#include "../incs/ht.h"

static int	ht_hash(const char *s, const int a, const int m)
{
	long	hash;
	int		i;
	size_t	s_len;

	s_len = ft_strlen(s);
	hash = 0;
	i = -1;
	while ((unsigned int)++i < s_len)
		hash += (long)ft_pow(a, s_len - (i + 1)) * (int)s[i];
	hash = hash % m;
	return ((int)hash);
}

int	ht_get_hash(const char *s, const int bucket, const int attempt)
{
	int	hash_a;
	int	hash_b;

	hash_a = ht_hash(s, HT_PRIME_1, bucket);
	hash_b = ht_hash(s, HT_PRIME_2, bucket);
	return ((hash_a + (attempt * (hash_b + 1))) % bucket);
}
