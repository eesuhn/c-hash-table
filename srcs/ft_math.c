#include "../incs/ft.h"

long	ft_pow(int nb, unsigned int pow)
{
	unsigned int	i;
	long			val;

	if (pow == 0)
		return (1);
	i = 0;
	val = 1;
	while (i++ < pow)
		val *= nb;
	return (val);
}
