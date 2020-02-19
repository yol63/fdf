NAME = fdf
COM = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = ./includes/
HEAD_H = fdf.h
SOUS = ./srcs/
SOUS_FIL = base.c \
		   check.c \
		   fdf.c \
		   ft_coor.c \
		   ft_isdigite.c \
		   helpers.c \
		   keys.c \
		   mouse.c \
		   ft_raelatoi.c
LIB_F = ./libft/
LIB = libft.a
LIB_C = -L $(LIB_F) -lft
MLX_F = /usr/local/lib/
MLX_C = -L $(MLX_F) -lmlx
OBJS = $(SOUS_FIL:.c=.o)
SOUS_F = $(addprefix $(SOUS), $(SOUS_FIL))
OBJS_F = $(addprefix $(BIN), $(OBJS))
REMOVE = rm -rf
BIN = ./bin/
FRAME = -framework OpenGL -framework Appkit


all: $(NAME)
$(NAME): $(OBJS) $(SOUS)
	make -C $(LIB_F) all && \
	$(COM) $(FLAGS) -o $@ $(OBJS_F) -I $(HEAD) $(LIB_C) $(MLX_C) $(FRAME)
$(OBJS):%.o: $(SOUS)%.c | $(BIN)
	$(COM) $(FLAGS) -c $< -o $(BIN)$@ -I $(HEAD)
$(BIN):
	mkdir $@
clean:
	@$(REMOVE) $(OBJS_F) $(BIN)
	@make -C $(LIB_F) clean
fclean: clean
	@$(REMOVE) $(NAME) $(BIN)
	@make -C $(LIB_F) fclean
re: fclean all
