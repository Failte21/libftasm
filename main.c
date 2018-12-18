#include "libfts.h"
#include <stdio.h>

int test_bzero()
{
	char	*a;
	char	*b;
	int		i;

	i = 500;
	a = (char *)malloc(i);
	b = (char *)malloc(i);
	while (i > 0)
	{
		memset(a, 'a', i);
		memcpy(b, a, i);
		ft_bzero(a, i);
		bzero(b, i);
		if (memcmp(a,b,10))
		{
			printf("KO\n");
			return (1);
		}
		i--;
	}
	printf("OK\n");
	return (0);
}

int main()
{
	int	err;

	err = 0;
	err += test_bzero();
	return (err);
}
