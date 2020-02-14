#!bin/bash/

gcc -Wall -Wextra -Werror base.c mouse.c ft_coor.c keys.c ft_isdigite.c fdf.c helpers.c check.c fdf.h mlx.h get_next_line.c get_next_line.h -L./minilibx_macos -lmlx -L ./libft -lft -framework OpenGL -framework AppKit
