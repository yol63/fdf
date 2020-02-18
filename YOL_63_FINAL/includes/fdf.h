/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:11:17 by romarash          #+#    #+#             */
/*   Updated: 2020/02/17 19:49:42 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

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
	float			z1;
	float			z2;
	unsigned int				color1;
    unsigned int				color2;
}					t_cor;

typedef	struct		s_handle
{
	int				key;
	int				shiftx;
	int				shifty;
	float			zoom;
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
}					t_handle;

typedef struct		s_red
{
	float			del_x;
	float			del_y;
	float			x;
	float			y;
	float			max;
}					t_red;

int					ft_draw(t_map *start, t_handle *data);
void				ft_error(int exit_code, char *message);
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
t_cor				ft_isom(t_handle *data, t_cor *prev);
t_cor				ft_blank1(t_handle *data, t_cor *prev);
t_cor				ft_blank2(t_handle *data, t_cor *prev);
t_cor				ft_blank3(t_handle *data, t_cor *prev);
int					ft_mouse_key(int key, int x, int y, t_handle *data);
void				ft_rotate_x(t_handle *data, t_cor *cor);
void				ft_rotate_y(t_handle *data, t_cor *cor);
void				ft_rotate_z(t_handle *data, t_cor *cor);
int					ft_check_wei(char **split, int wid);
#endif
