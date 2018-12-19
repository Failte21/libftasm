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
	free(a);
	free(b);
	return (0);
}

int test_strcat()
{
	char	*a;
	char	*b;
	int		i;
	
	i = 10;
	a = (char *)malloc(i);
	b = (char *)malloc(i);
	memset(a, 'a', 3);
	memset(b, 'b', 3);
	ft_strcat(a,b);
	printf("%s\n", a);
	return (0);
}

int test_strlen()
{
	int	a;
	int b;

	a = strlen("Hello world");
	b = ft_strlen("Hello world");
	printf("real: %d, mine: %d\n", a, b);
	return (0);
}

int main()
{
	int	err;

	err = 0;
	// err += test_bzero();
	// err += test_strcat();
	err += test_strlen();
	return (err);
}
