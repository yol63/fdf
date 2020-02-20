/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:21:38 by aophion           #+#    #+#             */
/*   Updated: 2020/02/20 16:47:31 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_num_keys(int key, t_handle *data)
{
	if (key == 125)
		if (data->h > -25)
			data->h = data->h - 0.05;
	if (key == 126)
		if (data->h < 25)
			data->h = data->h + 0.05;
	if (key == 84)
		data->shifty += 15;
	if (key == 91)
		data->shifty -= 15;
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

	if (data->key == 4)
	{
		menu = "Up - num8, Down - num2, Left - num4, Right - num6";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x90FF80, menu);
		menu = "BLANK XY - 1, XZ - 2, YZ - 3";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0x90FF80, menu);
		menu = "ISO - num0, ZOOM : num(+/-) , Z change - use arrows ";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0x90FF80, menu);
		menu = "Z, A, X, S, C, D - rotation";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 55, 0x90FF80, menu);
		menu = "4 - colors, 5 - white";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0x90FF80, menu);
		menu = "EXIT - Esc/Close window, j - hide menu";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xD080FF, menu);
	}
	else
	{
		menu = "Press 'h' to show menu";
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xD080FF, menu);
	}
}

double	ft_abs(double n)
{
	if (n < 0)
		n = -n;
	return (n);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_min(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
