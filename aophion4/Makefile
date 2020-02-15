NAME = fdf

LIB_PATH = ./libft

LIB_INC = ./libft/includes/

LIBFT = ./libft/libft.a

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = get_next_line.c \
	  check.c \
	  fdf.c \
	  ft_coor.c \
	  ft_isdigite.c \
	  helpers.c \
	  keys.c \
	  mouse.c
	
INCLUDES_FILES = get_next_line.h \
				 fdf.h 

INC_DIR = ./includes/

INCLUDES = $(addpreffix $(INCP_DIR), $(INCLUDES_FILES))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC))

OBJ_DIR = ./objects/

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -L ./minilibx_macos -lmlx $(FRAMEWORKS)


$(OBJ_DIR)%.o: %.c $(INCLUDES)
	mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_INC)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean
	make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean
	make -C minilibx_macos/ fclean

re: fclean all

.PHONY: clean fclean re make all
