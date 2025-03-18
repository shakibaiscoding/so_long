NAME = so_long
LIBFT = ./libft/libft.a
MLXLIB = MLX42/build/libmlx42.a
LIBMLX = ./MLX42
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
HEADERS	= -I ./include -I $(LIBMLX)/include
FLAGSMLX	= -ldl -lglfw -pthread -lm
SRCS	=	srcs/flood_fill.c \
			srcs/init_game.c \
			srcs/input_handler.c \
			srcs/maps_check.c \
			srcs/render_map.c \
			srcs/so_long.c \
			srcs/utils.c \
			srcs/load_map.c \
			srcs/map_reproduce.c \
			srcs/initiation.c \
			srcs/error_generator.c \
			srcs/render_assets.c \
			srcs/open_map.c \
			srcs/assest_check.c \
			srcs/load_map_second.c
OBJS	= ${SRCS:.c=.o}

all: $(LIBMLX) $(MLXLIB) $(NAME)
$(LIBMLX):
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

$(MLXLIB): $(LIBMLX)
	@cmake -B $(LIBMLX)/build -S $(LIBMLX) -DCMAKE_BUILD_TYPE=Release
	@cmake --build $(LIBMLX)/build -j4


$(LIBFT):
	@$(MAKE) -C ./libft/


$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(LIBFT) -L$(LIBMLX)/build -lmlx42 $(FLAGSMLX) $(HEADERS) -o $(NAME)
	@echo "THE GAME CREATED"



clean:
	@echo "REMOVING OBJECT FILES"
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJS)
	@echo "OBJECT FILES REMOVED"

fclean: clean
	@echo "REMOVING THE GAME"
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@rm -rf $(LIBMLX)/build
	@echo "THE GAME REMOVED"

re: fclean all

.PHONY: all clean fclean re libmlx
