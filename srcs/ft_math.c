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

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= nb / i)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 2;
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
