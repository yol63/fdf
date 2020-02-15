/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:11:17 by romarash          #+#    #+#             */
/*   Updated: 2020/02/14 16:11:17 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include "get_next_line.h"
# include <math.h>
# include "mlx.h"

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_map	*next;
}					t_map;

typedef struct		s_cor
{
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	int				z1;
	int				z2;
	int				color1;
	int				color2;
}					t_cor;

typedef	struct		s_handle
{
	int				key;
	int				shiftx;
	int				shifty;
	int				zoom;
	int				hei;
	int				wid;
	float			h;
	float			rad;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*map;
	int				proj;
	int				bits;
	int				size;
	int				endian;
	void			*img;
	char			*draw;
	float			dec_x;
	float			dec_y;
	float			dec_z;
	int				flag;
}					t_handle;

int					ft_draw(t_map *start, t_handle *data);
void				ft_error(int error);
t_map				*ft_lstnews(void);
void				ft_lstdels(t_map **alst);
void				ft_null_free(char *buf);
int					ft_atoi_base(char *str, int base);
int					ft_isdigite(char *ch);
t_map				*ft_fill_map(int x, t_handle *data, char **split,
		t_map *map);
void				ft_num_keys(int key, t_handle *data);
void				ft_filler(t_handle *data, int flag);
void				ft_menu(t_handle *data);
float				ft_abs(float n);
float				ft_max(float a, float b);
float				ft_min(float a, float b);
t_cor				ft_isom(t_handle *data, t_map *map1, t_map *map2);
t_cor				ft_blank1(t_handle *data, t_map *map1, t_map *map2);
t_cor		ft_blank2(t_handle *data, t_map *map1, t_map *map2);
t_cor		ft_blank3(t_handle *data, t_map *map1, t_map *map2);
int					ft_mouse_key(int key, int x, int y, t_handle *data);
void				ft_rotate_x(t_handle *data, t_cor *cor, t_map *map1, t_map *map2);
void				ft_rotate_y(t_handle *data, t_cor *cor, t_map *map1, t_map *map2);
void				ft_rotate_z(t_handle *data, t_cor *cor, t_map *map1, t_map *map2);
int					ft_check_wei(char **split, int wid);
#endif
