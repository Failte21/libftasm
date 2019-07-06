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

int _test_isalpha(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isalpha(*s);
	int ret_b = ft_isalpha(*s);
	printf("%c: isalpha: %d, ft_isalpha: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isalpha(s + 1);
}

int _test_isalpha_wide(char *s)
{
	int wide = *s | 0x1000;
 
	if (*s == 0)
		return 0;
	int ret_a = isalpha(wide);
	int ret_b = ft_isalpha(wide);
	printf("0x%X: isalpha: %d, ft_isalpha: %d\n", wide, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isalpha(s + 1);
}

int test_isalpha()
{
	printf("-----------ISALPHA----------\n");
	return
	_test_isalpha("Hello, world!, @Yolo #AsM4Life") +
	_test_isalpha_wide("Hello, world!, @Yolo #AsM4Life");
}

int _test_isdigit(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isdigit(*s);
	int ret_b = ft_isdigit(*s);
	printf("%c: isdigit: %d, ft_isdigit: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isdigit(s + 1);
}

int _test_isdigit_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isdigit(*s | 0x1000);
	int ret_b = ft_isdigit(*s | 0x1000);
	
	printf("0x%X: isdigit: %d, ft_isdigit: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isdigit_wide(s + 1);
}

int test_isdigit()
{
	printf("-----------ISDIGIT----------\n");
	return 
	_test_isdigit("123... Hey U ! 456...1 more T1me !!") +
	_test_isdigit_wide("123... Hey U ! 456...1 more T1me !!");
}

int _test_isalnum(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isalnum(*s);
	int ret_b = ft_isalnum(*s);
	printf("%c: isalnum: %d, ft_isalnum: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isalnum(s + 1);
}

int _test_isalnum_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isalnum(*s | 0x1000);
	int ret_b = ft_isalnum(*s | 0x1000);
	
	printf("0x%X: isalnum: %d, ft_isalnum: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isalnum_wide(s + 1);
}

int test_isalnum()
{
	printf("-----------ISALNUM----------\n");
	return 
	_test_isalnum("123... Hey U ! 456...1 more T1me !!") +
	_test_isalnum_wide("123... Hey U ! 456...1 more T1me !!");
}


int _test_isascii(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isascii(*s);
	int ret_b = ft_isascii(*s);
	printf("%c: isascii: %d, ft_isascii: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isascii(s + 1);
}

int _test_isascii_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isascii(*s | 0x1000);
	int ret_b = ft_isascii(*s | 0x1000);
	
	printf("0x%X: isascii: %d, ft_isascii: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isascii_wide(s + 1);
}

int _test_isascii_range(int current, int n)
{
	if (n == 0) {
		return 0;
	}
	int ret_a = isascii(current);
	int ret_b = ft_isascii(current);
	
	printf("0x%X: isascii: %d, ft_isascii: %d\n", current, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isascii_range(current - 100, n - 1) + _test_isascii_range(current + 100, n - 1);
}

int test_isascii()
{
	printf("-----------ISASCII----------\n");
	return 
	_test_isascii("123... Hey U ! 456...1 more T1me !!") +
	_test_isascii_wide("123... Hey U ! 456...1 more T1me !!") +
	_test_isascii_range(0, 10);
}

int _test_isprint_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isprint(*s | 0x1000);
	int ret_b = ft_isprint(*s | 0x1000);
	
	printf("0x%X: isprint: %d, ft_isprint: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isprint_wide(s + 1);
}

int _test_isprint_range(int current, int n)
{
	if (n == 0) {
		return 0;
	}
	int ret_a = isprint(current);
	int ret_b = ft_isprint(current);
	
	printf("0x%X: isprint: %d, ft_isprint: %d\n", current, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isprint_range(current - 100, n - 1) + _test_isprint_range(current + 100, n - 1);
}

int _test_isprint(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = isprint(*s);
	int ret_b = ft_isprint(*s);
	printf("%c: isprint: %d, ft_isprint: %d\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_isprint(s + 1);
}

int test_isprint()
{
	printf("-----------ISPRINT----------\n");
	return 
	_test_isprint("123... Hey U ! 456...1 more T1me !!") +
	_test_isprint_wide("123... Hey U ! 456...1 more T1me !!") +
	_test_isprint_range(0, 10);
}

int _test_toupper_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = toupper(*s | 0x1000);
	int ret_b = ft_toupper(*s | 0x1000);
	
	printf("0x%X: toupper: %d, ft_toupper: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_toupper_wide(s + 1);
}

int _test_toupper_range(int current, int n)
{
	if (n == 0) {
		return 0;
	}
	int ret_a = toupper(current);
	int ret_b = ft_toupper(current);
	
	printf("0x%X: toupper: %d, ft_toupper: %d\n", current, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_toupper_range(current - 100, n - 1) + _test_toupper_range(current + 100, n - 1);
}

int _test_toupper(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = toupper(*s);
	int ret_b = ft_toupper(*s);
	printf("%c: toupper: %c, ft_toupper: %c\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_toupper(s + 1);
}

int test_toupper()
{
	printf("-----------TOUPPER----------\n");
	return 
	_test_toupper("123... Hey U ! 456...1 more T1me !!") +
	_test_toupper_wide("123... Hey U ! 456...1 more T1me !!") +
	_test_toupper_range(0, 10);
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
	err += print_partial("ISALPHA", test_isalpha());
	err += print_partial("ISDIGIT", test_isdigit());
	err += print_partial("ISALNUM", test_isalnum());
	err += print_partial("ISASCII", test_isascii());
	err += print_partial("ISPRINT", test_isprint());
	err += print_partial("TOUPPER", test_toupper());
	wchar_t w  = 0x1000 | 'A';
	return (err);
}
