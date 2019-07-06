NAME = libfts.a
AS = nasm

OBJS = $(SRCS:.s=.o)

SRCS = ft_bzero.s
SRCS += ft_strcat.s
SRCS += ft_strlen.s
SRCS += ft_puts.s
SRCS += ft_islower.s
SRCS += ft_isupper.s
SRCS += ft_isalpha.s
SRCS += ft_isdigit.s
SRCS += ft_isalnum.s
SRCS += ft_isascii.s
SRCS += ft_isprint.s

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