NAME = libfts.a
AS = nasm

OBJS = $(SRCS:.s=.o)

SRCS = ft_bzero.s

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $@ $^
	@ranlib $@

$(OBJS): $(SRCS)
	$(AS) -f macho64 $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all