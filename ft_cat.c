#include "libfts.h"

int main(int argc, char **argv)
{
	int fd = argc > 1 ? open(argv[1], O_RDONLY) : 0;
	ft_cat(fd);
	return 0;
}