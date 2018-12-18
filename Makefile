NAME = libfts.a
AS = nasm

OBJS = $(SRCS:.s=.o)

SRCS = ft_bzero.s
SRCS += ft_strcat.s

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $@ $^
	@ranlib $@

%.o: %.s
	$(AS) -f macho64 $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all