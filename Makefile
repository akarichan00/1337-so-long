NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
MlxFlags =  -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit
Cflags = -Wall -Wextra -Werror 

libft = lib/libft/libft.a
printf = lib/printf/libftprintf.a

srcs =  src/so_long.c src/parse_map1.c src/parse_map2.c  src/parse_map3.c src/drawing.c src/drawing2.c src/drawing3.c src/drawing4.c
objs = $(srcs:.c=.o)

bonus_srcs = bonus/so_long_bonus.c bonus/parse_map1_bonus.c bonus/parse_map2_bonus.c bonus/parse_map3_bonus.c bonus/drawing_bonus.c bonus/drawing2_bonus.c bonus/drawing3_bonus.c bonus/drawing4_bonus.c
bonus_objs = $(bonus_srcs:bonus/%.c=bonus/%.o)

RESET = \033[0m
BOLD = \033[1m
PURPLE = \033[35m

all : $(NAME)

$(NAME): $(objs) $(libft) $(printf) ../MLX42/build/libmlx42.a ../MLX42/build/libglfw3.a
	$(CC) $(Cflags) $(MlxFlags) -o $@ $^ $(libft) $(printf)
	@echo "$(BOLD)$(PURPLE)$(NAME) created successfully!$(RESET)"

$(libft): 
	@echo "$(BOLD)$(PURPLE)Building LIBFT$(RESET)"
	make -C lib/libft

$(printf): 
	@echo "$(BOLD)$(PURPLE)Building PRINTF$(RESET)"
	make -C lib/printf

src/%.o: src/%.c include/so_long.h
	$(CC) $(Cflags) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(bonus_objs) $(libft) $(printf) ../MLX42/build/libmlx42.a ../MLX42/build/libglfw3.a
	$(CC) $(Cflags) $(MlxFlags) -o $@ $^ $(libft) $(printf)
	@echo "$(BOLD)$(PURPLE)$(NAME_BONUS) created successfully!$(RESET)"

bonus/%.o: bonus/%.c include/so_long_bonus.h
	$(CC) $(Cflags) -c $< -o $@

clean:
	@echo "$(BOLD)$(PURPLE)Cleaning objects...$(RESET)"
	rm -f $(objs)
	rm -f $(bonus_objs)
	make -C lib/libft clean
	make -C lib/printf clean

fclean: clean
	@echo "$(BOLD)$(PURPLE)Cleaning $(NAME)...$(RESET)"
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C lib/libft fclean
	make -C lib/printf fclean

re: fclean all
