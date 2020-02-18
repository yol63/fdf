/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:21:38 by aophion           #+#    #+#             */
/*   Updated: 2020/02/17 19:25:27 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_num_keys(int key, t_handle *data)
{
	if (key == 125)
		if (data->h > -100)
			data->h = data->h - 0.05;
	if (key == 126)
		if (data->h < 100)
			data->h = data->h + 0.05;
	if (key == 84)
		data->shifty -= 15;
	if (key == 91)
		data->shifty += 15;
	if (key == 88)
		data->shiftx += 15;
	if (key == 86)
		data->shiftx -= 15;
	if (key == 78)
		data->zoom -= data->zoom / 6;
	if (key == 69)
		if (data->zoom < 100)
			data->zoom += data->zoom / 6;
	if (key == 92)
		data->rad += 0.0154498;
	if (key == 89)
		data->rad -= 0.0154498;
}

void	ft_menu(t_handle *data)
{
	char	*menu;

	menu = "Up - 8, Down - 2, Left - 4, Right - 6";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x80FF91, menu);
	menu = "BLANK XY - 1, XZ - 2, YZ - 3";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x80FF91, menu);
	menu = "ISO - 0, ZOOM : + - , change high - use arrows ";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x80FF91, menu);
	menu = "Z, A, X, S, C, D - ROTATION";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, 0x80FF91, menu);
	menu = "EXIT - Ecs";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0x80FF91, menu);
}

float	ft_abs(float n)
{
	if (n < 0)
		n = -n;
	return (n);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
