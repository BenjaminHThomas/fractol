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
LIBFTDIR	= $(PRINTF_DIR)libft

INCS	=	-I $(LIBFTDIR)\
			-I ./includes/\
			-I ./includes/ft_printf\
			-I ./minilibx-linux/\

LINKS	= -L$(PRINTF_DIR) -lftprintf \
		  -L$(LIBFTDIR) -lft

all: $(OBJDIR) $(MLX) $(PRINTF) $(NAME)

bonus: all

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(COMPILER) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(MLX):
	@echo "Making minilibx..."
	@make -sC $(MLXDIR)

$(PRINTF):
	@echo "Making printf..."
	@make -sC $(PRINTF_DIR)

$(NAME): $(OBJS) $(MLX) $(PRINTF)
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKS) $(MLX) $(PRINTF) -lXext -lX11 -lm

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJDIR)
	@make clean -sC $(MLXDIR)
	@make clean -sC $(PRINTF_DIR)

fclean: clean
	@echo "Removing fractol program..."
	@rm -f $(NAME)
	@make fclean -sC $(PRINTF_DIR)
	@make clean -sC $(MLXDIR)

re: fclean all

.PHONY: all clean fclean re bonus
