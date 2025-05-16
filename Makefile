CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -flto -march=native -g -I./src/minilibx-linux -I./includes -I./src/libft
LDFLAGS = -L./minilibx-linux -lmlx_Linux -lX11 -lXext -L./src/libft -lft -O3 -flto -march=native

TARGET = fractol

OBJ_PATH = obj/
LIBFT_DIR = src/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS =	src/main.c \
	src/calcs.c \
	src/helper_inits.c \
	src/render.c
		
OBJS = $(SRCS:src/%.c=$(OBJ_PATH)%.o)
HEADERS = includes/fractol.h

$(OBJ_PATH)%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_LIB) $(TARGET)

$(TARGET): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
