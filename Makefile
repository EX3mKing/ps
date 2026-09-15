NAME = push_swap
# LIBFTDIR = libft
# LIBFT = $(LIBFTDIR)/libft.a
# PRINTFDIR = ft_printf
# PRINTF = $(PRINTFDIR)/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror # -Ift_printf -Ilibft

SRCS = main.c \
	ft_util_mem.c \
	ft_util_str.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTFDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) # $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#	$(PRINTF) $(LIBFT) -> add above , before -o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
# 	make clean -C $(PRINTFDIR)
# 	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
# 	make fclean -C $(PRINTFDIR)
# 	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
