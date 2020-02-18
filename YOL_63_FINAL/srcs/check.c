/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:19:49 by romarash          #+#    #+#             */
/*   Updated: 2020/02/17 20:37:50 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_cor	*ft_cor(t_handle *data, t_map *map1, t_map *map2, t_cor *cor)
{
	cor->x1 = map1->x;
	cor->x2 = map2->x;
	cor->y1 = map1->y;
	cor->y2 = map2->y;
	cor->z1 = map1->z * data->h;
	cor->z2 = map2->z * data->h;
	cor->color1 = map1->color;
	if (map1->color == -1)
		cor->color1 = 0xffffff;
	cor->color2 = map2->color;
	if (map2->color == -1)
		cor->color2 = 0xffffff;
	if (data->proj == 1 || data->proj == 0)
		(*cor) = ft_isom(data, cor);
	if (data->proj == 2)
		(*cor) = ft_blank1(data, cor);
	if (data->proj == 3)
		(*cor) = ft_blank2(data, cor);
	if (data->proj == 4)
		(*cor) = ft_blank3(data, cor);
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

void			wr_linex(t_handle *data, t_cor *cor)
{
	t_red	bres;

	bres.del_x = cor->x2 - cor->x1;
	bres.del_y = cor->y2 - cor->y1;
	bres.max = ft_max(ft_abs(bres.del_x), ft_abs(bres.del_y));
	bres.x = bres.del_x / bres.max;
	bres.y = bres.del_y / bres.max;
	while ((int)(cor->x2 - cor->x1) != 0
			|| (int)(cor->y2 - cor->y1) != 0)
	{
		ft_save_pixel(data, cor->x1, cor->y1, cor->color1);
		cor->y1 += bres.y;
		cor->x1 += bres.x;
	}
	ft_save_pixel(data, cor->x1, cor->y1, cor->color1);
}

int				ft_draw(t_map *start, t_handle *data)
{
	t_map	*tmp;
	t_cor	cor;

	tmp = start;
	while (start->next)
	{
		tmp = start;
		while (tmp->next && !(tmp->y == (start->y + 1)
					&& tmp->x > start->x))
		{
			if ((tmp->x == (start->x + 1)) && (tmp->y == start->y))
				wr_linex(data, ft_cor(data, start, tmp, &cor));
			if ((tmp->x == start->x) && (tmp->y == (start->y + 1)))
				wr_linex(data, ft_cor(data, start, tmp, &cor));
			tmp = tmp->next;
		}
		start = start->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	ft_menu(data);
	return (1);
}
