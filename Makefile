NAME = push_swap
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ift_printf -Ilibft

SRCS = start.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTFDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(PRINTFDIR)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTFDIR)
	make fclean -C $(LIBFTDIR)

re: fclean all

test:
	

.PHONY: all clean fclean re
