NAME = so_long

CC = cc

Cflags = -Wall -Wextra -Werror

libft = lib/libft/libft.a
printf = lib/printf/libftprintf.a

srcs =  src/so_long.c src/parse_map1.c src/parse_map2.c 
objs = $(srcs:.c=.o)

RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[93m
PURPLE = \033[35m

all : $(NAME)

$(NAME): $(objs) $(libft) $(printf)
	$(CC) $(Cflags) -o $@ $^ $(libft) $(printf)
	@echo "$(BOLD)$(PURPLE)$(NAME) created successfully!$(RESET)"

$(libft): 
	@echo "$(BOLD)$(PURPLE)Building LIBFT$(RESET)"
	make -C lib/libft

$(printf): 
	@echo "$(BOLD)$(PURPLE)Building PRINTF$(RESET)"
	make -C lib/printf

src/%.o: src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BOLD)$(PURPLE)Cleaning objects...$(RESET)"
	rm -f $(objs)
	make -C lib/libft clean
	make -C lib/printf clean

fclean:
	@echo "$(BOLD)$(PURPLE)Cleaning $(NAME)...$(RESET)"
	rm -f $(NAME)
	make -C lib/libft fclean
	make -C lib/printf fclean

re: fclean all
