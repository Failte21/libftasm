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

int _test_tolower_wide(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = tolower(*s | 0x1000);
	int ret_b = ft_tolower(*s | 0x1000);
	
	printf("0x%X: tolower: %d, ft_tolower: %d\n", *s | 0x1000, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_tolower_wide(s + 1);
}

int _test_tolower_range(int current, int n)
{
	if (n == 0) {
		return 0;
	}
	int ret_a = tolower(current);
	int ret_b = ft_tolower(current);
	
	printf("0x%X: tolower: %d, ft_tolower: %d\n", current, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_tolower_range(current - 100, n - 1) + _test_tolower_range(current + 100, n - 1);
}

int _test_tolower(char *s)
{
	if (*s == 0)
		return 0;
	int ret_a = tolower(*s);
	int ret_b = ft_tolower(*s);
	printf("%c: tolower: %c, ft_tolower: %c\n", *s, ret_a, ret_b);
	if (ret_a != ret_b)
		return 1;
	return _test_tolower(s + 1);
}

int test_tolower()
{
	printf("-----------TOLOWER----------\n");
	return 
	_test_tolower("123... Hey U ! 456...1 more T1me !!") +
	_test_tolower_wide("123... Hey U ! 456...1 more T1me !!") +
	_test_tolower_range(0, 10);
}

int _test_memset(char *s[7], int c, int i)
{
	if (i < 0)
		return 0;
	char	*clone_a = strdup(s[i]);
	char	*clone_b = strdup(s[i]);
	int		len = strlen(s[i]);
	char	*s_a = memset(clone_a, i, len);
	char	*s_b = ft_memset(clone_b, i, len);
	printf("memset: %s\nft_memset: %s\n", s_a, s_b);
	return memcmp(s_a, s_b, len) + _test_memset(s, c, i - 1);
}

int test_memset()
{
	printf("-----------MEMSET----------\n");
	char	*strs[7] = {
		"Hello world!\n",
		"Open the gates !!!\n",
		"Hat er sich von 0 auf 100 in den Raum gesetzt\n",
		"Nunc egestas faucibus sapien ut ultrices. Curabitur convallis tellus a dignissim varius. Sed ac condimentum nulla. Proin vehicula, quam ac dictum accumsan, velit elit condimentum ipsum, ut sodales nibh urna nec ex. Nam vehicula felis nulla. Praesent scelerisque ex ipsum, sit amet facilisis lorem luctus in. Duis lacus urna, ultrices vel nunc id, consectetur sodales ante.\n",
		"Ut scelerisque, enim nec eleifend rutrum, diam augue condimentum velit, vitae consectetur risus lacus vel ex. Fusce quis felis ut dui malesuada accumsan vehicula et erat. Suspendisse feugiat id justo nec sollicitudin. Curabitur sodales nibh neque, id fringilla nulla tincidunt nec. Suspendisse vel felis eget enim bibendum ornare. Sed pulvinar est quis eros fringilla, vitae egestas leo hendrerit. Donec rutrum consequat nunc, mattis vehicula arcu molestie id. Donec rutrum velit ut rhoncus pulvinar.\n",
		"Nam sollicitudin faucibus nulla. In hac habitasse platea dictumst. Donec at blandit tortor, vitae molestie libero. Mauris porttitor nec est nec venenatis. Nunc tortor quam, vehicula ut malesuada in, sodales vitae enim. Donec ac placerat nunc, auctor facilisis urna. Donec blandit lectus ac nunc luctus, et bibendum est aliquam. Curabitur suscipit, est euismod tristique porta, felis mauris dignissim enim, vel mattis metus lacus et erat. Curabitur laoreet dui at lorem sollicitudin, et auctor ligula dapibus. Fusce ut dui sem. Etiam vel varius arcu. Phasellus eget tincidunt quam.",
		"Nullam fringilla, ipsum eget venenatis vulputate, quam sem venenatis urna, a vehicula turpis est non ipsum. Integer posuere elit id nibh gravida fringilla sed non urna. Vestibulum euismod dignissim purus sit amet sodales. Vivamus scelerisque sed sapien ac euismod. Quisque volutpat leo vel consectetur ornare. Donec pulvinar, elit eu pellentesque tristique, risus nisl aliquet urna, ut ultrices ex turpis et orci. Pellentesque mattis congue nulla et maximus. Nullam accumsan auctor consectetur. Nullam cursus nisi elit, consectetur convallis diam facilisis nec. Donec a massa sit amet ipsum feugiat efficitur. Sed dapibus ullamcorper dictum. Vivamus mollis convallis purus et efficitur. Nam commodo, sapien sed finibus interdum, lorem quam vulputate leo, eget sagittis leo libero eu massa. Integer volutpat, nunc sit amet condimentum pulvinar, nibh nulla luctus diam, non consectetur justo arcu id tortor. Aliquam ut tellus a neque lobortis lobortis vel et metus."
	};
	return
	_test_memset(strs, 'a', 6) +
	_test_memset(strs, 'a' | 0x0100, 6);
}

int _test_memcpy(char *s[7], int i)
{
	if (i == 0)
		return 0;
	char	*cpy = strdup("empty..............................");
	char	*cpy_b = strdup("empty..............................");
	char	*res = ft_memcpy(cpy, strdup(s[i]), 15);
	char	*res_b = memcpy(cpy_b, strdup(s[i]), 15);
	printf("memcpy: %s\nft_memcpy: %s\n\n", res_b, res);
	return
	memcmp(res, res_b, 15) +
	memcmp(cpy, cpy_b, 15)
	+ _test_memcpy(s, i - 1);
}

int test_memcpy()
{
	printf("-----------MEMCPY----------\n");
	char	*strs[7] = {
		"Hello world!\n",
		"Open the gates !!!\n",
		"Hat er sich von 0 auf 100 in den Raum gesetzt\n",
		"Nunc egestas faucibus sapien ut ultrices. Curabitur convallis tellus a dignissim varius. Sed ac condimentum nulla. Proin vehicula, quam ac dictum accumsan, velit elit condimentum ipsum, ut sodales nibh urna nec ex. Nam vehicula felis nulla. Praesent scelerisque ex ipsum, sit amet facilisis lorem luctus in. Duis lacus urna, ultrices vel nunc id, consectetur sodales ante.\n",
		"Ut scelerisque, enim nec eleifend rutrum, diam augue condimentum velit, vitae consectetur risus lacus vel ex. Fusce quis felis ut dui malesuada accumsan vehicula et erat. Suspendisse feugiat id justo nec sollicitudin. Curabitur sodales nibh neque, id fringilla nulla tincidunt nec. Suspendisse vel felis eget enim bibendum ornare. Sed pulvinar est quis eros fringilla, vitae egestas leo hendrerit. Donec rutrum consequat nunc, mattis vehicula arcu molestie id. Donec rutrum velit ut rhoncus pulvinar.\n",
		"Nam sollicitudin faucibus nulla. In hac habitasse platea dictumst. Donec at blandit tortor, vitae molestie libero. Mauris porttitor nec est nec venenatis. Nunc tortor quam, vehicula ut malesuada in, sodales vitae enim. Donec ac placerat nunc, auctor facilisis urna. Donec blandit lectus ac nunc luctus, et bibendum est aliquam. Curabitur suscipit, est euismod tristique porta, felis mauris dignissim enim, vel mattis metus lacus et erat. Curabitur laoreet dui at lorem sollicitudin, et auctor ligula dapibus. Fusce ut dui sem. Etiam vel varius arcu. Phasellus eget tincidunt quam.",
		"Nullam fringilla, ipsum eget venenatis vulputate, quam sem venenatis urna, a vehicula turpis est non ipsum. Integer posuere elit id nibh gravida fringilla sed non urna. Vestibulum euismod dignissim purus sit amet sodales. Vivamus scelerisque sed sapien ac euismod. Quisque volutpat leo vel consectetur ornare. Donec pulvinar, elit eu pellentesque tristique, risus nisl aliquet urna, ut ultrices ex turpis et orci. Pellentesque mattis congue nulla et maximus. Nullam accumsan auctor consectetur. Nullam cursus nisi elit, consectetur convallis diam facilisis nec. Donec a massa sit amet ipsum feugiat efficitur. Sed dapibus ullamcorper dictum. Vivamus mollis convallis purus et efficitur. Nam commodo, sapien sed finibus interdum, lorem quam vulputate leo, eget sagittis leo libero eu massa. Integer volutpat, nunc sit amet condimentum pulvinar, nibh nulla luctus diam, non consectetur justo arcu id tortor. Aliquam ut tellus a neque lobortis lobortis vel et metus."
	};
	return
	_test_memcpy(strs, 6);
}

int _test_strdup(char *s[7], int i)
{
	if (i == 0)
		return 0;
	char	*cpy = strdup(s[i]);
	char	*cpy_b = strdup(s[i]);
	printf("strdup: %s\n\nft_strdup: %s\n\n\n", cpy, cpy_b);
	int res = memcmp(cpy, cpy_b, strlen(s[i]));
	free(cpy);
	free(cpy_b);
	return res + _test_strdup(s, i - 1);
}

int test_strdup()
{
	printf("-----------STRDUP----------\n");
	char	*strs[7] = {
		"Hello world!\n",
		"Open the gates !!!\n",
		"Hat er sich von 0 auf 100 in den Raum gesetzt\n",
		"Nunc egestas faucibus sapien ut ultrices. Curabitur convallis tellus a dignissim varius. Sed ac condimentum nulla. Proin vehicula, quam ac dictum accumsan, velit elit condimentum ipsum, ut sodales nibh urna nec ex. Nam vehicula felis nulla. Praesent scelerisque ex ipsum, sit amet facilisis lorem luctus in. Duis lacus urna, ultrices vel nunc id, consectetur sodales ante.\n",
		"Ut scelerisque, enim nec eleifend rutrum, diam augue condimentum velit, vitae consectetur risus lacus vel ex. Fusce quis felis ut dui malesuada accumsan vehicula et erat. Suspendisse feugiat id justo nec sollicitudin. Curabitur sodales nibh neque, id fringilla nulla tincidunt nec. Suspendisse vel felis eget enim bibendum ornare. Sed pulvinar est quis eros fringilla, vitae egestas leo hendrerit. Donec rutrum consequat nunc, mattis vehicula arcu molestie id. Donec rutrum velit ut rhoncus pulvinar.\n",
		"Nam sollicitudin faucibus nulla. In hac habitasse platea dictumst. Donec at blandit tortor, vitae molestie libero. Mauris porttitor nec est nec venenatis. Nunc tortor quam, vehicula ut malesuada in, sodales vitae enim. Donec ac placerat nunc, auctor facilisis urna. Donec blandit lectus ac nunc luctus, et bibendum est aliquam. Curabitur suscipit, est euismod tristique porta, felis mauris dignissim enim, vel mattis metus lacus et erat. Curabitur laoreet dui at lorem sollicitudin, et auctor ligula dapibus. Fusce ut dui sem. Etiam vel varius arcu. Phasellus eget tincidunt quam.",
		"Nullam fringilla, ipsum eget venenatis vulputate, quam sem venenatis urna, a vehicula turpis est non ipsum. Integer posuere elit id nibh gravida fringilla sed non urna. Vestibulum euismod dignissim purus sit amet sodales. Vivamus scelerisque sed sapien ac euismod. Quisque volutpat leo vel consectetur ornare. Donec pulvinar, elit eu pellentesque tristique, risus nisl aliquet urna, ut ultrices ex turpis et orci. Pellentesque mattis congue nulla et maximus. Nullam accumsan auctor consectetur. Nullam cursus nisi elit, consectetur convallis diam facilisis nec. Donec a massa sit amet ipsum feugiat efficitur. Sed dapibus ullamcorper dictum. Vivamus mollis convallis purus et efficitur. Nam commodo, sapien sed finibus interdum, lorem quam vulputate leo, eget sagittis leo libero eu massa. Integer volutpat, nunc sit amet condimentum pulvinar, nibh nulla luctus diam, non consectetur justo arcu id tortor. Aliquam ut tellus a neque lobortis lobortis vel et metus."
	};
	return
	_test_strdup(strs, 6);
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
	err += print_partial("BZERO", test_bzero());
	err += print_partial("STRCAT", test_strcat());
	err += print_partial("STRLEN", test_strlen());
	err += print_partial("PUTS", test_puts());
	err += print_partial("ISALPHA", test_isalpha());
	err += print_partial("ISDIGIT", test_isdigit());
	err += print_partial("ISALNUM", test_isalnum());
	err += print_partial("ISASCII", test_isascii());
	err += print_partial("ISPRINT", test_isprint());
	err += print_partial("TOUPPER", test_toupper());
	err += print_partial("TOLOWER", test_tolower());
	err += print_partial("MEMSET", test_memset());
	err += print_partial("MEMCPY", test_memcpy());
	err += print_partial("STRDUP", test_strdup());
	return (err);
}
