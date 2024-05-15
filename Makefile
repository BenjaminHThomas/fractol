
# steps
# 1. bring in .a library from minilib
# 2. bring in libft.a
# 3. have the makefile make minilib & libft to create the .a file
# 4. include minilib, libft and includes
# 5. have the makefile clean all the folders


NAME = fractol

C_FILES		= main.c
SRCDIR		= srcs
SRCS		= $(addprefix $(SRCDIR)/,$(C_FILES))

CFLAGS		= -g3 -Iincludes -Iminilibx-linux -lmlx -lXext -lX11 -Lmlx_linux
COMPILER	= gcc

MLX			= libmlx.a
MLXDIR		= minilibx-linux

LIBFT		= libft.a
LIBFTDIR	= libft

$(MLX)
	@echo "Making minilibx..."
	make -sC $(MLXDIR)

$(LIBFT)
	@echo "Making libft..."
	make -sC $(LIBFTDIR)

$(NAME):
	$(COMPILER) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(MLX) $(LIBFT) $(NAME)

clean:
	rm -f $(SRCDIR)/*.o

flcean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re