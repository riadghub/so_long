NAME = so_long

SRCS =	srcs/check.c								\
		srcs/ft_printf.c							\
		srcs/ft_printint.c							\
		srcs/ft_printstr.c							\
		srcs/map.c									\
		srcs/map_utils.c							\
		srcs/map_utils2.c							\
		srcs/map_utils3.c							\
		srcs/main.c									\
		srcs/move.c									\
		srcs/move_utils.c							\
		srcs/game.c									\
		srcs/get_next_line.c						\
		srcs/get_next_line_utils.c					\
		srcs/render.c								\
		srcs/render_utils.c							\
		srcs/textures.c								\
		srcs/utils.c								\
		srcs/utils2.c								\
		srcs/ft_split.c								\

HEADERS = ./includes/

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz


# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Règle principale
all: ${NAME}

# Règle pour compiler les fichiers objets
%.o : %.c
	@echo "$(BLUE)Compiling $(YELLOW)$< $(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} -I$(MLX_DIR) -c $< -o $@

# Règle pour compiler la MiniLibX
$(MLX):
	@echo "$(YELLOW)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)MiniLibX compiled!$(RESET)"

# Règle pour lier le programme final
${NAME}: ${OBJS} $(MLX)
	@echo "$(GREEN)Linking objects into $(YELLOW)${NAME}$(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} ${MLX_FLAGS} -o ${NAME}
	@echo "$(GREEN)Build complete!$(RESET)"


# Règle pour nettoyer les fichiers objets
clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@echo "$(GREEN)Clean complete!$(RESET)"

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean : clean
	@echo "$(RED)Removing $(YELLOW)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@echo "$(GREEN)Full clean complete!$(RESET)"

# Règle pour recompiler entièrement le projet
re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

# Règle pour exécuter le programme
run : all
	@echo "$(GREEN)Running $(YELLOW)${NAME}$(RESET)..."
	@./${NAME} maps/map2.ber

.PHONY: all clean fclean re run