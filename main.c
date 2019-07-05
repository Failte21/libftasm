#include "libfts.h"
#include <stdio.h>

int test_bzero()
{
	char	*a;
	char	*b;
	int		i;
	int		n_tests;

	n_tests = 500;
	i = n_tests;
	a = (char *)malloc(i);
	b = (char *)malloc(i);
	printf("-----------BZERO----------\n");
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
	printf("OK on %d tests\n", n_tests);
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

	printf("-----------STRLEN----------\n");
	a = strlen("Hello world");
	b = ft_strlen("Hello world");
	printf("real: %d, mine: %d\n", a, b);
	return (0);
}

int _test_puts(char *s)
{
	int len = strlen(s);

	if (len == 0)
		return 0;

	int ret_a = puts(s);
	int ret_b = ft_puts(s);

	if (ret_a != ret_b)
		return 1;
	return _test_puts(s + 1);
}

int test_puts()
{
	printf("-----------PUTS----------\n");
	return _test_puts("Hello, world!");
}

int main()
{
	int	err;

	err = 0;
	// err += test_bzero();
	// err += test_strcat();
	err += test_strlen();
	// return ft_puts("test______");
	// int len = ft_puts("test______");a
	err += test_puts();
	return (err);
}
