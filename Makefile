NAME = fractol

CFLAGS = -g3 -Wall -Werror -Wextra
COMPILER = gcc

C_FILES = main.c \
		  mlx_utils.c \
		  calculations.c \
		  image_utils.c \
		  events.c \
		  help.c

SRCDIR = srcs/
SRCS = $(addprefix $(SRCDIR), $(C_FILES))

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(C_FILES:.c=.o))

MLX_LIB = libmlx.a
MLXDIR = minilibx-linux/
MLX = $(MLXDIR)$(MLX_LIB)

LIBFT_LIB = libft.a
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)$(LIBFT_LIB)

INCS =	-I ./includes/\
		-I ./libft/\
		-I ./minilibx-linux/

all: $(OBJDIR) $(MLX) $(LIBFT) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLX):
	echo "Making minilibx..."
	@make -C $(MLXDIR)

$(LIBFT):
	echo "Making libft..."
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm

clean:
	echo "Cleaning objects..."
	@rm -rf $(OBJDIR)
	@make clean -C $(MLXDIR)
	@make clean -C $(LIBFTDIR)

fclean: clean
	echo "Removing fractol program..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@make clean -C $(MLXDIR)

re: fclean all

.PHONY: all clean fclean re

