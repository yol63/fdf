NAME = fdf
COM = gcc
HEAD_FDF = ./includes/
HEAD_L = ./libft/
HEAD_LIB = libft.h
HEAD_H = fdf.h
HEAD_F = $(HEAD_FDF) \
		$(HEAD_L)
HEADS = $(addprefix -I, $(HEAD_F))
LIB_F = ./libft/
LIB = libft.a
LIB_D = $(addprefix $(LIB_F), $(LIB))
LIB_C = -L $(LIB_F) -lft
MLX_F = /usr/local/lib/
MLX_C = -L $(MLX_F) -lmlx
FRAME = -framework OpenGL -framework Appkit
SOUS = ./srcs/
SOUS_FIL = base.c \
		   check.c \
		   fdf.c \
		   ft_coor.c \
		   ft_isdigite.c \
		   helpers.c \
		   le_color.c \
		   keys.c \
		   ft_raelatoi.c\
		   mouse.c
OBJS = $(SOUS_FIL:.c=.o)
SOUS_F = $(addprefix $(SOUS), $(SOUS_FIL))
OBJS_F = $(addprefix $(BIN), $(OBJS))
TRASH = fdf.dSYM
BIN = ./bin/
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

.PHONY: all clean re

all: $(NAME)
$(NAME): $(OBJS_F) $(HEAD_FDF)$(HEAD_H) $(LIB_D)
	$(COM) $(FLAGS) -o $@ $(OBJS_F) $(HEADS) $(LIB_C) $(MLX_C) $(FRAME)
$(LIB_D): $(LIB_F)
	$(MAKE) -sC $(LIB_F) all
$(BIN)%.o: $(SOUS)%.c
	mkdir -p $(BIN) && \
	$(COM) $(FLAGS) -c $< -o $@ $(HEADS)
clean:
	@$(REMOVE) $(OBJS_F) $(BIN) $(TRASH)
	@make -sC $(LIB_F) clean
fclean: clean
	@$(REMOVE) $(NAME)
	@make -sC $(LIB_F) fclean
re: fclean all
