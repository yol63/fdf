/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:21:38 by aophion           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:57 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_num_keys(int key, t_handle *data)
{
	if (key == 84)
		data->shifty -= 15;
	if (key == 91)
		data->shifty += 15;
	if (key == 88)
		data->shiftx += 15;
	if (key == 86)
		data->shiftx -= 15;
	if (key == 78)
		data->zoom -= data->zoom / 3;
	if (key == 69)
		data->zoom += 3;
	if (key == 92)
		data->rad += 0.0154498;
	if (key == 89)
		data->rad -= 0.0154498;
}

void	ft_menu(t_handle *data)
{
	char	*menu;

	menu = "ALARM";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0xAAAAAA, menu);
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
