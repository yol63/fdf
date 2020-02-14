/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:32:52 by aophion           #+#    #+#             */
/*   Updated: 2020/02/14 12:25:08 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_key(int key, int x, int y, t_handle *data)
{
	int		cent_x;
	int		cent_y;

	cent_x = 500;
	cent_y = 500;	
//	printf("%d - x, %d - y\n", x, y);
	if (key == 5)
		data->zoom += 1;
	if (key == 4)
		data->zoom -= data->zoom / 3;
	if(key == 2)
	{
		if(x < cent_x)
			data->shiftx += (cent_x - x) / 3;
		else if(x > cent_x)
			data->shiftx -= (x - cent_x) / 3;
		if(y < cent_y)
			data->shifty += (cent_y - y) / 3;
		else if (y > cent_y)
			data->shifty -= (y - cent_y) / 3;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data->map, data);
	return (1);
}
