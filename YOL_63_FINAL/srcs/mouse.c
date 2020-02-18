/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:32:52 by aophion           #+#    #+#             */
/*   Updated: 2020/02/17 19:40:20 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_key(int key, int x, int y, t_handle *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	if (key == 5 && data->zoom < 100)
		data->zoom += data->zoom / 6;
	if (key == 4)
		data->zoom -= data->zoom / 6;
	if (key == 2)
	{
		if (x < 500)
			data->shiftx += (500 - x) / 3;
		else if (x > 500)
			data->shiftx -= (x - 500) / 3;
		if (y < 500)
			data->shifty += (500 - y) / 3;
		else if (y > 500)
			data->shifty -= (y - 500) / 3;
	}
	if (!(data->img = mlx_new_image(data->mlx_ptr, 1000, 1000)))
		ft_error(1, "error\n");
	data->draw = mlx_get_data_addr(data->img, &data->bits,
			&data->size, &data->endian);
	ft_draw(data->map, data);
	return (1);
}
