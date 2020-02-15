/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:19:49 by romarash          #+#    #+#             */
/*   Updated: 2020/02/14 15:42:48 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cor	ft_cor(t_handle *data, t_map *map1, t_map *map2)
{
	t_cor	cor;

	if (data->proj == 1 || data->proj == 0)
		cor = ft_isom(data, map1, map2);
    if (data->proj == 2)
        cor = ft_blank1(data, map1, map2);
    if (data->proj == 3)
        cor = ft_blank2(data, map1, map2);
    if (data->proj == 4)
        cor = ft_blank3(data, map1, map2);

	return (cor);
}

void			ft_save_pixel(t_handle *data, int x, int y, int color)
{
	int				i;
	unsigned int	c;

	if (y < 1000 && x < 1000 && y > 0 && x > 0)
	{
		i = x * data->bits / 8 + y * data->size;
		c = mlx_get_color_value(data->mlx_ptr, color);
		data->draw[i++] = c;
		data->draw[i++] = c >> 8;
		data->draw[i] = c >> 16;
	}
}

int				ft_color(t_cor *cor, float shag)
{
	int		col;

	col = 0;
	col += ((cor->color2 - cor->color1) / (int)shag);
	col += ((cor->color2 - cor->color1) / (int)shag) >> 8;
	col += ((cor->color2 - cor->color1) / (int)shag) >> 16;
	return (col);
}

void			wr_linex(t_handle *data, t_cor *cor)
{
	float	shag_x;
	float	shag_y;
	float	shag_c;
	float	max;

	max = ft_max(ft_abs(cor->x2 - cor->x1), ft_abs(cor->y2 - cor->y1));
	shag_x = (cor->x2 - cor->x1) / max;
	shag_y = (cor->y2 - cor->y1) / max;
	shag_c = (cor->color1 - cor->color2);
	shag_c /= max;
	while (ft_abs((int)(cor->y2 - cor->y1)) != 0
			|| ft_abs((int)(cor->x2 - cor->x1)) != 0)
	{
		if (cor->color1 != cor->color2)
			cor->color1 = ft_color(cor, shag_c);
		ft_save_pixel(data, cor->x1, cor->y1, cor->color1);
		cor->x1 += shag_x;
		cor->y1 += shag_y;
	}
}

int				ft_draw(t_map *start, t_handle *data)
{
	t_map	*tmp;
	t_cor	cor;

	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->draw = mlx_get_data_addr(data->img,
			&data->bits, &data->size, &data->endian);
	tmp = start;
	while (start->next)
	{
		tmp = start;
		while (tmp->next && !(tmp->y == (start->y + 1)
					&& tmp->x > start->x))
		{
			if ((tmp->x == (start->x + 1)) && (tmp->y == start->y))
			{
				cor = ft_cor(data, start, tmp);
				wr_linex(data, &cor);
			}
			if ((tmp->x == start->x) && (tmp->y == (start->y + 1)))
			{
				cor = ft_cor(data, start, tmp);
				wr_linex(data, &cor);
			}
			tmp = tmp->next;
		}
		start = start->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
