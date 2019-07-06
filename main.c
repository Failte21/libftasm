#include "libfts.h"
#include <stdio.h>

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define BLUE	"\x1B[34m"
#define BASE	"\x1B[0m"

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

// TODO: improve
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

int _test_islower(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = islower(*s);
	int ret_b = ft_islower(*s);
	printf("%c: islower: %d, ft_islower: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_islower(s + 1);
}

int test_islower()
{
	printf("-----------ISLOWER----------\n");
	return _test_islower("Hello, world!, @Yolo #AsM4Life");
}

int print_partial(char *test_name, int passed)
{

	if (passed == 0)
		printf("%s%s: SUCCESS !", GREEN, test_name);
	else
		printf("%s%s: FAILURE", RED, test_name);
	printf("%s\n\n", BASE);
	return passed;
} 

int main()
{
	int	err;

	err = 0;
	// err += print_partial("BZERO", test_bzero());
	// err += print_partial("STRCAT", test_strcat());
	err += print_partial("STRLEN", test_strlen());
	err += print_partial("PUTS", test_puts());
	err += print_partial("ISLOWER", test_islower());
	return (err);
}
