#include "libfts.h"
#include <stdio.h>
#include <stdbool.h>

# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define BLUE	"\x1B[34m"
# define BASE	"\x1B[0m"
# define CHECK "\xE2\x9C\x93"
# define X "\xe2\x9c\x97"

# define LEN	7

char	*strs[LEN] = {
	"Hello world!",
	"Open the gates !!!",
	"Hat er sich von 0 auf 100 in den Raum gesetzt",
	"Érable 🍁",
	" Sapin 🌲",
	"Nam sollicitudin faucibus nulla. In hac habitasse .",
	"Nullam fringilla, ipsum eget venenatis vulputate, quam sem."
};

bool g_verbose = false;

void print_test(bool assertion) {
	if (assertion) {
		printf("%s%s ", GREEN, CHECK);
	} else {
		printf("%s%s ", RED, X);
	}
	printf("%s", BASE);
}

int cmp_bzero(size_t i)
{
	char	*expected = malloc(i);
	char	*value = malloc(i);
	
	ft_bzero(value, i);
	bzero(expected, i);
	int assert_cmp = memcmp(expected, value, i);
	g_verbose && printf("With len %zu", i);
	print_test(assert_cmp == 0);
	free(expected);
	free(value);
	g_verbose && printf("\n");
	return assert_cmp;
}

int _test_bzero(size_t i)
{
	if (i == 0)
		return cmp_bzero(i);
	return cmp_bzero(i) + _test_bzero(i / 2);
}

int test_bzero()
{
	size_t	n_tests = __INT_MAX__ / 8;

	printf("-----------BZERO----------\n");
	return _test_bzero(n_tests);
}

int cmp_strcat(char *s, char *to_append)
{
	int len = strlen(s) + strlen(to_append) + 1; // +1 is for terminating \0
	char *clone_a = malloc(len);
	char *clone_b = malloc(len);

	char *start_a = strcpy(clone_a, s);
	char *start_b = strcpy(clone_b, s);

	char *expected = strcat(start_a, to_append);
	char *value = ft_strcat(start_b, to_append);

	int assert_ret = value - start_b; // make sure we kept the same pointer
	int assert_cmp = strcmp(expected, value);
	free(expected);
	free(value);
	print_test(assert_ret + assert_cmp == 0);
	g_verbose && printf("\n");
	return assert_cmp + assert_ret;
}

int _test_strcat(char *as[LEN], char *bs[LEN], int i)
{
	g_verbose && printf("%s   ======>    %s ", as[i], bs[i]);
	if (i == 0)
		return cmp_strcat(as[i], bs[LEN - i - 1]);
	return cmp_strcat(as[i], bs[LEN - i - 1]) + _test_strcat(as, bs, i - 1);
}

int test_strcat()
{
	printf("-----------STRCAT----------\n");
	return _test_strcat(strs, strs, LEN - 1);
}

int cmp_strlen(char *s)
{
	g_verbose && printf("%s  ", s);
	size_t value = ft_strlen(s);
	size_t expected = strlen(s);

	size_t diff = value - expected;
	print_test(diff == 0);
	g_verbose && printf("\n");
	return diff;
}

int _test_strlen(char *s[LEN], int i)
{
	if (i == 0)
		return cmp_strlen(s[i]);
	return cmp_strlen(s[i]) + _test_strlen(s, i - 1);
}

int test_strlen()
{
	printf("-----------STRLEN----------\n");
	return _test_strlen(strs, LEN - 1);
}

int cmp_puts(char *s)
{
	int expected = puts(s);
	int value = ft_puts(s);

	int assert_return = expected - value;
	print_test(assert_return == 0);
	printf("\n");
	return assert_return;
}

int _test_puts(char *strs[LEN], int i)
{
	if (i == 0)
		return cmp_puts(strs[i]);
	return cmp_puts(strs[i]) + _test_puts(strs, i - 1);
}

int test_puts()
{
	printf("-----------PUTS----------\n");
	return _test_puts(strs, LEN - 1);
}

int cmp_isalpha(int c)
{
	int assert_cmp = isalpha(c) - ft_isalpha(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_isalpha(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_isalpha(*s);
	return cmp_isalpha(*s) + _test_isalpha(s + 1);
}

int _test_isalpha_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_isalpha(wide);
	return cmp_isalpha(wide) + _test_isalpha_wide(s + 1);
}

int test_isalpha()
{
	printf("-----------ISALPHA----------\n");
	int basic = _test_isalpha("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_isalpha_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isdigit(int c)
{
	int assert_cmp = isdigit(c) - ft_isdigit(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_isdigit(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_isdigit(*s);
	return cmp_isdigit(*s) + _test_isdigit(s + 1);
}

int _test_isdigit_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_isdigit(wide);
	return cmp_isdigit(wide) + _test_isdigit_wide(s + 1);
}

int test_isdigit()
{
	printf("-----------ISDIGIT----------\n");
	int basic = _test_isdigit("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_isdigit_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isalnum(int c)
{
	int assert_cmp = isalnum(c) - ft_isalnum(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_isalnum(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_isalnum(*s);
	return cmp_isalnum(*s) + _test_isalnum(s + 1);
}

int _test_isalnum_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_isalnum(wide);
	return cmp_isalnum(wide) + _test_isalnum_wide(s + 1);
}

int test_isalnum()
{
	printf("-----------ISALNUM----------\n");
	int basic = _test_isalnum("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_isalnum_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isascii(int c)
{
	int assert_cmp = isascii(c) - ft_isascii(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_isascii(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_isascii(*s);
	return cmp_isascii(*s) + _test_isascii(s + 1);
}

int _test_isascii_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_isascii(wide);
	return cmp_isascii(wide) + _test_isascii_wide(s + 1);
}

int test_isascii()
{
	printf("-----------ISASCII----------\n");
	int basic = _test_isascii("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_isascii_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isprint(int c)
{
	int assert_cmp = isprint(c) - ft_isprint(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_isprint(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_isprint(*s);
	return cmp_isprint(*s) + _test_isprint(s + 1);
}

int _test_isprint_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_isprint(wide);
	return cmp_isprint(wide) + _test_isprint_wide(s + 1);
}

int test_isprint()
{
	printf("-----------ISPRINT----------\n");
	int basic = _test_isprint("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_isprint_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_toupper(int c)
{
	int assert_cmp = toupper(c) - ft_toupper(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_toupper(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_toupper(*s);
	return cmp_toupper(*s) + _test_toupper(s + 1);
}

int _test_toupper_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_toupper(wide);
	return cmp_toupper(wide) + _test_toupper_wide(s + 1);
}

int test_toupper()
{
	printf("-----------TOUPPER----------\n");
	int basic = _test_toupper("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_toupper_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_tolower(int c)
{
	int assert_cmp = tolower(c) - ft_tolower(c);
	print_test(assert_cmp == 0);
	return assert_cmp;
}

int _test_tolower(char *s)
{
	g_verbose && printf("%c", *s);
	if (*s == 0)
		return cmp_tolower(*s);
	return cmp_tolower(*s) + _test_tolower(s + 1);
}

int _test_tolower_wide(char *s)
{
	int wide = *s | 0x1000;
	g_verbose && printf("0x%x", wide);
	if (*s == 0)
		return cmp_tolower(wide);
	return cmp_tolower(wide) + _test_tolower_wide(s + 1);
}

int test_tolower()
{
	printf("-----------TOLOWER----------\n");
	int basic = _test_tolower("Hello, world!, @Yolo #AsM4Life");
	int wide = _test_tolower_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_memset(char *s, int c)
{
	g_verbose && printf("%s ====> %c ", s, c);
	char	*clone_a = strdup(s);
	char	*clone_b = strdup(s);
	int		len = strlen(s);
	char	*value = memset(clone_a, c, len);
	char	*expected = ft_memset(clone_b, c, len);
	int		assert_return = value - clone_a;
	int		assert_cmp = memcmp(value, expected, len);
	print_test(assert_cmp + assert_return == 0);
	g_verbose && printf("\n");
	return assert_cmp + assert_return;
}

int _test_memset(char *s[7], int c, int i)
{
	if (i < 0)
		return 0;
	return cmp_memset(s[i], c) + _test_memset(s, c, i - 1);
}

int test_memset()
{
	printf("-----------MEMSET----------\n");
	int base = _test_memset(strs, 'a', LEN - 1);
	int wide = _test_memset(strs, 'a' | 0x0100, LEN - 1);
	return base + wide;
}

int cmp_memcpy(char *s)
{
	char	*cpy = strdup("empty..............................");
	char	*cpy_b = strdup("empty..............................");
	char	*value = ft_memcpy(cpy, s, 15);
	char	*expected = memcpy(cpy_b, s, 15);

	int assert_return = value - cpy;
	int assert_cmp = memcmp(value, expected, 15);
	free(value);
	free(expected);
	g_verbose && printf("%s ", s);
	print_test(assert_return + assert_return == 0);
	g_verbose && printf("\n");
	return assert_return + assert_cmp;
}

int _test_memcpy(char *s[LEN], int i)
{
	if (i == 0)
		return cmp_memcpy(s[i]);
	return cmp_memcpy(s[i]) + _test_memcpy(s, i - 1);
}

int test_memcpy()
{
	printf("-----------MEMCPY----------\n");
	return _test_memcpy(strs, LEN - 1);
}

int cmp_strdup(char *s)
{
	char	*expected = strdup(s);
	char	*value = ft_strdup(s);
	int assert_cmp = strcmp(expected, value);
	g_verbose && printf("%s ", s);
	print_test(assert_cmp == 0);
	free(value);
	free(expected);
	g_verbose && printf("\n");
	return assert_cmp;
}

int _test_strdup(char *s[7], int i)
{
	if (i == 0)
		return cmp_strdup(s[i]);
	return cmp_strdup(s[i]) + _test_strdup(s, i - 1);
}

int test_strdup()
{
	printf("-----------STRDUP----------\n");
	return _test_strdup(strs, LEN - 1);
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

int main(int argc, char **argv)
{
	int	err;

	if (argc > 1 && (!strcmp(argv[1], "--verbose") || (!strcmp(argv[1], "-v")))) g_verbose = true;

	err = 0;
	err += print_partial("BZERO", test_bzero());
	err += print_partial("STRCAT", test_strcat());
	err += print_partial("STRLEN", test_strlen());
	err += print_partial("PUTS", test_puts());
	err += print_partial("ISALPHA", test_isalpha());
	err += print_partial("ISALNUM", test_isalnum());
	err += print_partial("ISDIGIT", test_isdigit());
	err += print_partial("ISASCII", test_isascii());
	err += print_partial("ISPRINT", test_isprint());
	err += print_partial("TOUPPER", test_toupper());
	err += print_partial("TOLOWER", test_tolower());
	err += print_partial("MEMSET", test_memset());
	err += print_partial("MEMCPY", test_memcpy());
	err += print_partial("STRDUP", test_strdup());
	return print_partial("OVERALL", err);
}
