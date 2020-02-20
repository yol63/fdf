/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:32:52 by aophion           #+#    #+#             */
/*   Updated: 2020/02/20 14:57:46 by aophion          ###   ########.fr       */
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
		if (x < 860)
			data->shiftx += (860 - x) / 3;
		else if (x > 860)
			data->shiftx -= (x - 860) / 3;
		if (y < 510)
			data->shifty += (510 - y) / 3;
		else if (y > 510)
			data->shifty -= (y - 510) / 3;
	}
	if (!(data->img = mlx_new_image(data->mlx_ptr, 1920, 1080)))
		ft_error(2, "error\n");
	data->draw = mlx_get_data_addr(data->img, &data->bits,
			&data->size, &data->endian);
	ft_draw(data->map, data);
	return (1);
}
