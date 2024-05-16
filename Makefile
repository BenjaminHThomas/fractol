
NAME = fractol

CFLAGS		= -g3
COMPILER	= gcc

C_FILES		= main.c
SRCDIR		= srcs/
SRCS		= $(SRCDIR)$(C_FILES)

OBJDIR		= obj/
OFILES		= $(C_FILES:.c=.o)
OBJS		= $(OBJDIR)$(OFILES)

MLX_LIB		= libmlx.a
MLXDIR		= minilibx-linux/
MLX			= $(MLXDIR)$(MLX_LIB)

LIBFT_LIB	= libft.a
LIBFTDIR	= libft/
LIBFT		= $(LIBFTDIR)$(LIBFT_LIB)

INCS		= -I ./includes/\
			  -I ./libft/\
			  -I ./minilibx-linux/

all: $(MLX) $(LIBFT) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(COMPILER) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJS): $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(MLX):
	@echo "Making minilibx..."
	@make -sC $(MLXDIR)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFTDIR)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJDIR)
	@make clean -C $(MLXDIR)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@echo "Removing fractol program..."
	@rm -f $(NAME)
	@rm -f $(LIBFTDIR)$(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
