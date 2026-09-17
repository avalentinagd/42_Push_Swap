NAME        = push_swap
CC          = cc -g
CFLAGS      = -Wall -Wextra -Werror

# 1. Se eliminó src/ft_split.c porque ya viene incluido dentro de la libft.a
SRCS        = src/main.c src/stats.c src/stack_utils.c src/parse_flags.c \
              src/parse_utils.c src/parser.c 

RM          = rm -f
LIBFT_PATH  = libft
LIBFT       = $(LIBFT_PATH)/libft.a
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

# 2. Corregida la compilación del ejecutable enlazando correctamente la libft
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

# Regla para compilar la libft si no está creada o si ha cambiado
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re