#include "libfts.h"

int main(int argc, char **argv)
{
	int fd = argc > 1 ? open(argv[1], O_RDONLY) : 0;
	printf("fd: %d\n", fd);
	if (fd == -1)
		return 1;
	ft_cat(fd);
	return 0;
}