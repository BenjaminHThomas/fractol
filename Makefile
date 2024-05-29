NAME = fractol

CFLAGS = -Wall -Werror -Wextra
COMPILER = cc

C_FILES = main.c \
		  mlx_utils.c \
		  calculations.c \
		  image_utils.c \
		  image_utils_bonus.c \
		  events.c \
		  atof.c \
		  help.c

SRCDIR = srcs/
SRCS = $(addprefix $(SRCDIR), $(C_FILES))

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(C_FILES:.c=.o))

MLX_LIB = libmlx.a
MLXDIR = minilibx-linux/
MLX = $(MLXDIR)$(MLX_LIB)

PRINTF_LIB	= libftprintf.a
PRINTF_DIR	= ./includes/ft_printf/
PRINTF		= $(PRINTF_DIR)$(PRINTF_LIB)

INCS =	-I ./includes/\
		-I ./includes/ft_printf\
		-I ./minilibx-linux/

all: $(OBJDIR) $(MLX) $(PRINTF) $(NAME)

bonus: all

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLX):
	@echo "Making minilibx..."
	@make -C $(MLXDIR)

$(PRINTF):
	@echo "Making printf..."
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(MLX) $(PRINTF)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(PRINTF) -lXext -lX11 -lm

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJDIR)
	@make clean -C $(MLXDIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@echo "Removing fractol program..."
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MLXDIR)

re: fclean all

.PHONY: all clean fclean re bonus

