#include "libfts.h"
#include <stdio.h>

# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define BLUE	"\x1B[34m"
# define BASE	"\x1B[0m"

# define LEN	7

char	*strs[LEN] = {
	"Hello world!\n",
	"Open the gates !!!\n",
	"Hat er sich von 0 auf 100 in den Raum gesetzt\n",
	"Nunc egestas faucibus sapien ut ultrices. Curabitur convallis tellus a dignissim varius. Sed ac condimentum nulla. Proin vehicula, quam ac dictum accumsan, velit elit condimentum ipsum, ut sodales nibh urna nec ex. Nam vehicula felis nulla. Praesent scelerisque ex ipsum, sit amet facilisis lorem luctus in. Duis lacus urna, ultrices vel nunc id, consectetur sodales ante.\n",
	"Ut scelerisque, enim nec eleifend rutrum, diam augue condimentum velit, vitae consectetur risus lacus vel ex. Fusce quis felis ut dui malesuada accumsan vehicula et erat. Suspendisse feugiat id justo nec sollicitudin. Curabitur sodales nibh neque, id fringilla nulla tincidunt nec. Suspendisse vel felis eget enim bibendum ornare. Sed pulvinar est quis eros fringilla, vitae egestas leo hendrerit. Donec rutrum consequat nunc, mattis vehicula arcu molestie id. Donec rutrum velit ut rhoncus pulvinar.\n",
	"Nam sollicitudin faucibus nulla. In hac habitasse platea dictumst. Donec at blandit tortor, vitae molestie libero. Mauris porttitor nec est nec venenatis. Nunc tortor quam, vehicula ut malesuada in, sodales vitae enim. Donec ac placerat nunc, auctor facilisis urna. Donec blandit lectus ac nunc luctus, et bibendum est aliquam. Curabitur suscipit, est euismod tristique porta, felis mauris dignissim enim, vel mattis metus lacus et erat. Curabitur laoreet dui at lorem sollicitudin, et auctor ligula dapibus. Fusce ut dui sem. Etiam vel varius arcu. Phasellus eget tincidunt quam.",
	"Nullam fringilla, ipsum eget venenatis vulputate, quam sem venenatis urna, a vehicula turpis est non ipsum. Integer posuere elit id nibh gravida fringilla sed non urna. Vestibulum euismod dignissim purus sit amet sodales. Vivamus scelerisque sed sapien ac euismod. Quisque volutpat leo vel consectetur ornare. Donec pulvinar, elit eu pellentesque tristique, risus nisl aliquet urna, ut ultrices ex turpis et orci. Pellentesque mattis congue nulla et maximus. Nullam accumsan auctor consectetur. Nullam cursus nisi elit, consectetur convallis diam facilisis nec. Donec a massa sit amet ipsum feugiat efficitur. Sed dapibus ullamcorper dictum. Vivamus mollis convallis purus et efficitur. Nam commodo, sapien sed finibus interdum, lorem quam vulputate leo, eget sagittis leo libero eu massa. Integer volutpat, nunc sit amet condimentum pulvinar, nibh nulla luctus diam, non consectetur justo arcu id tortor. Aliquam ut tellus a neque lobortis lobortis vel et metus."
};

int cmp_bzero(size_t i)
{
	char	*expected = malloc(i);
	char	*value = malloc(i);
	
	ft_bzero(value, i);
	bzero(expected, i);
	printf("With len %zu\n", i);
	int assert_cmp = memcmp(expected, value, i);
	printf("Compare: %s\n\n", assert_cmp == 0 ? "OK" : "KO");
	free(expected);
	free(value);
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

	// printf("start_b: 0x%X\n  value: 0x%X\n", start_b, value);
	// printf("ft_strcat: %s\n", value);
	// printf("strcat:    %s\n", expected);
	int assert_ret = value - start_b; // make sure we kept the same pointer
	printf("Return value: %s\n", assert_ret == 0 ? "OK" : "KO");
	int assert_cmp = strcmp(expected, value);
	printf("Compare     : %s\n", assert_cmp == 0 ? "OK" : "KO");
	printf("\n");
	free(expected);
	free(value);
	return assert_cmp + assert_ret;
}

int _test_strcat(char *as[LEN], char *bs[LEN], int i)
{
	printf("Test %d\n", i);
	if (i == 0)
		return cmp_strcat(as[i], bs[LEN - i - 1]);
	return cmp_strcat(as[i], bs[LEN - i - 1]) + _test_strcat(as, bs, i - 1);
}

int test_strcat()
{
	printf("-----------STRLEN----------\n");

	printf(">>>> Basic tests <<<<\n");
	return _test_strcat(strs, strs, LEN - 1);
}

int cmp_strlen(char *s)
{
	size_t value = ft_strlen(s);
	size_t expected = strlen(s);

	size_t diff = value - expected;
	printf("strlen:    %zu\n", expected);
	printf("ft_strlen: %zu\n", value);
	printf("%s\n\n", diff == 0 ? "OK" : "KO");
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
	int err = 0;
	printf("-----------STRLEN----------\n");
	printf(">>>> Basic tests <<<<\n");
	err += _test_strlen(strs, LEN - 1);
	return err;
}

int cmp_puts(char *s)
{
	int expected = puts(s);
	int value = ft_puts(s);

	int assert_cmp = expected - value;
	return assert_cmp;

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
	printf(">>>> Basic tests <<<<\n");
	return _test_puts(strs, LEN - 1);
}

int cmp_isalpha(int c)
{
	int assert_cmp = isalpha(c) - ft_isalpha(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_isalpha(char *s)
{
	if (*s == 0)
		return cmp_isalpha(*s);
	return cmp_isalpha(*s) + _test_isalpha(s + 1);
}

int _test_isalpha_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_isalpha(wide);
	return cmp_isalpha(wide) + _test_isalpha_wide(s + 1);
}

int test_isalpha()
{
	printf("-----------ISALPHA----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_isalpha("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_isalpha_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isdigit(int c)
{
	int assert_cmp = isdigit(c) - ft_isdigit(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_isdigit(char *s)
{
	if (*s == 0)
		return cmp_isdigit(*s);
	return cmp_isdigit(*s) + _test_isdigit(s + 1);
}

int _test_isdigit_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_isdigit(wide);
	return cmp_isdigit(wide) + _test_isdigit_wide(s + 1);
}

int test_isdigit()
{
	printf("-----------ISDIGIT----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_isdigit("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_isdigit_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isalnum(int c)
{
	int assert_cmp = isalnum(c) - ft_isalnum(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_isalnum(char *s)
{
	if (*s == 0)
		return cmp_isalnum(*s);
	return cmp_isalnum(*s) + _test_isalnum(s + 1);
}

int _test_isalnum_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_isalnum(wide);
	return cmp_isalnum(wide) + _test_isalnum_wide(s + 1);
}

int test_isalnum()
{
	printf("-----------ISALNUM----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_isalnum("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_isalnum_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isascii(int c)
{
	int assert_cmp = isascii(c) - ft_isascii(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_isascii(char *s)
{
	if (*s == 0)
		return cmp_isascii(*s);
	return cmp_isascii(*s) + _test_isascii(s + 1);
}

int _test_isascii_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_isascii(wide);
	return cmp_isascii(wide) + _test_isascii_wide(s + 1);
}

int test_isascii()
{
	printf("-----------ISASCII----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_isascii("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_isascii_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_isprint(int c)
{
	int assert_cmp = isprint(c) - ft_isprint(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_isprint(char *s)
{
	if (*s == 0)
		return cmp_isprint(*s);
	return cmp_isprint(*s) + _test_isprint(s + 1);
}

int _test_isprint_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_isprint(wide);
	return cmp_isprint(wide) + _test_isprint_wide(s + 1);
}

int test_isprint()
{
	printf("-----------ISPRINT----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_isprint("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_isprint_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_toupper(int c)
{
	int assert_cmp = toupper(c) - ft_toupper(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_toupper(char *s)
{
	if (*s == 0)
		return cmp_toupper(*s);
	return cmp_toupper(*s) + _test_toupper(s + 1);
}

int _test_toupper_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_toupper(wide);
	return cmp_toupper(wide) + _test_toupper_wide(s + 1);
}

int test_toupper()
{
	printf("-----------TOUPPER----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_toupper("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_toupper_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int cmp_tolower(int c)
{
	int assert_cmp = tolower(c) - ft_tolower(c);
	printf("0x%X: %s\n", c, assert_cmp == 0 ? "OK" : "KO");
	return assert_cmp;
}

int _test_tolower(char *s)
{
	if (*s == 0)
		return cmp_tolower(*s);
	return cmp_tolower(*s) + _test_tolower(s + 1);
}

int _test_tolower_wide(char *s)
{
	int wide = *s | 0x1000;
	if (*s == 0)
		return cmp_tolower(wide);
	return cmp_tolower(wide) + _test_tolower_wide(s + 1);
}

int test_tolower()
{
	printf("-----------TOLOWER----------\n");
	printf(">>>> Basic tests <<<<\n");
	int basic = _test_tolower("Hello, world!, @Yolo #AsM4Life");
	printf("\n>>>> With wide chars <<<<\n");
	int wide = _test_tolower_wide("Hello, world!, @Yolo #AsM4Life");
	return basic + wide;
}

int _cmp_memset(char *s, int c)
{
	char	*clone_a = strdup(s);
	char	*clone_b = strdup(s);
	int		len = strlen(s);
	char	*s_a = memset(clone_a, c, len);
	char	*s_b = ft_memset(clone_b, c, len);
	printf("memset: %s\nft_memset: %s\n", s_a, s_b);
	int err = memcmp(s_a, s_b, len);
	printf("diff: %d\n", err);
	return err;
}

int _test_memset(char *s[7], int c, int i)
{
	if (i < 0)
		return 0;
	return _cmp_memset(s[i], c) + _test_memset(s, c, i - 1);
}

int test_memset()
{
	int err = 0;

	printf("-----------MEMSET----------\n");
	printf(">>>> Basic tests <<<<\n");
	err += _test_memset(strs, 'a', LEN - 1);
	printf(">>>> Test with wildchar <<<<\n");
	err += _test_memset(strs, 'a' | 0x0100, LEN - 1);
	return err;
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
	return
	_test_memcpy(strs, LEN - 1);
}

int _test_strdup(char *s[7], int i)
{
	printf("Test %d\n", i);
	char	*expected = strdup(s[i]);
	char	*value = ft_strdup(s[i]);
	// printf("ft_strdup: %s", value);
	// printf("strdup:    %s\n", expected);
	int assert_cmp = strcmp(expected, value);
	printf("Compare: %s\n", assert_cmp == 0 ? "OK" : "KO");
	printf("\n");
	free(value);
	free(expected);
	if (i == 0)
		return 0;
	return assert_cmp + _test_strdup(s, i - 1);
}

int test_strdup()
{
	printf("-----------STRDUP----------\n");
	return
	_test_strdup(strs, LEN - 1);
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
