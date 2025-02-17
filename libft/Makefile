NAME = libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_DIR = ./libft
PRINTF_DIR = ./printf
GNL_DIR = ./getnextline
OBJ_DIR = ./obj

SRC_FILES = \
    $(wildcard $(SRC_DIR)/is/*.c) \
    $(wildcard $(SRC_DIR)/lst/*.c) \
    $(wildcard $(SRC_DIR)/mem/*.c) \
    $(wildcard $(SRC_DIR)/put/*.c) \
    $(wildcard $(SRC_DIR)/str/*.c) \
    $(wildcard $(PRINTF_DIR)/*.c) \
    $(wildcard $(GNL_DIR)/*.c)

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "[INFO] Librería $(NAME) creada correctamente."

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Librería $(NAME) eliminada."

re: fclean all

.PHONY: all clean fclean re
# cc -Wall -Wextra -Werror put_map.c -Llibraries/minilibx-linux -lmlx -lXext -lX11 -lm -o ponercolor
# comando para ejecutar 
