/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:11:17 by romarash          #+#    #+#             */
/*   Updated: 2020/02/19 18:09:28 by romarash         ###   ########.fr       */
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
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			z1;
	double			z2;
	unsigned int	color1;
	unsigned int	color2;
}					t_cor;

typedef	struct		s_handle
{
	int				key;
	int				shiftx;
	int				shifty;
	int				colorflag;
	int				maxz;
	double			zoom;
	int				hei;
	int				wid;
	double			h;
	double			rad;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*map;
	int				proj;
	int				bits;
	int				size;
	int				endian;
	void			*img;
	char			*draw;
	double			dec_x;
	double			dec_y;
	double			dec_z;
}					t_handle;

typedef struct		s_red
{
	double			del_x;
	double			del_y;
	double			x;
	double			y;
	double			max;
}					t_red;

int					ft_realatoi(const char *str);
void				ft_z_color(t_handle *data, t_map *map1,
		t_map *map2, t_cor *cor);
int					ft_draw(t_map *start, t_handle *data);
void				ft_error(int exit_code, char *message);
t_map				*ft_lstnews(void);
void				ft_lstdels(t_map **alst);
void				ft_null_free(char *buf);
int					ft_atoi_base(char *str, int base);
t_map				*ft_fill_map(int x, t_handle *data, char **split,
		t_map *map);
void				ft_num_keys(int key, t_handle *data);
void				ft_filler(t_handle *data, int flag);
void				ft_menu(t_handle *data);
double				ft_abs(double n);
double				ft_max(double a, double b);
double				ft_min(double a, double b);
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
