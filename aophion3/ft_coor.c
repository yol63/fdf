/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:56:28 by aophion           #+#    #+#             */
/*   Updated: 2020/02/14 15:56:07 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor		ft_isom(t_handle *data, t_map *map1, t_map *map2)
{
	t_cor	cor;

	cor.x1 = data->shiftx + ((map1->x - map1->y) * cos(data->rad)) * data->zoom;
	cor.x2 = data->shiftx + ((map2->x - map2->y) * cos(data->rad)) * data->zoom;
	cor.y1 = data->shifty + ((map1->x + map1->y) * sin(data->rad)
			- map1->z * data->h) * data->zoom;
	cor.y2 = data->shifty + ((map2->x + map2->y) * sin(data->rad)
			- map2->z * data->h) * data->zoom;
	cor.z1 = map1->z;
	cor.z2 = map2->z;
	if (map1->color == 0)
		cor.color1 = 0xffffff;
	else
		cor.color1 = map1->color;
	if (map2->color == 0)
		cor.color2 = 0xffffff;
	else
		cor.color2 = map2->color;
//	ft_putstr("SUCCESS\n");
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	ft_rotate_z(data, &cor);
	return (cor);
}

void		ft_rotate_x(t_handle *data, t_cor *cor)
{
	float	temp_y1;
	float	temp_z1;
	float	temp_y2;
	float	temp_z2;

	if (data->dec_x)
	{
		temp_y1 = cor->y1;
		temp_z1 = cor->z1;
		temp_y2 = cor->y2;
		temp_z2 = cor->z2;
		cor->y1 = temp_y1 * cos(data->dec_x) + temp_z1 * sin(data->dec_x);
		cor->z1 = -temp_y1 * sin(data->dec_x) + temp_z1 * cos(data->dec_x);
		cor->y2 = temp_y2 * cos(data->dec_x) + temp_z2 * sin(data->dec_x);
		cor->z2 = -temp_y2 * sin(data->dec_x) + temp_z2 * cos(data->dec_x);
	}
}

void		ft_rotate_y(t_handle *data, t_cor *cor)
{
	float	temp_x1;
	float	temp_z1;
	float	temp_x2;
	float	temp_z2;

	if (data->dec_y)
	{
		temp_x1 = cor->x1;
		temp_z1 = cor->z1;
		temp_x2 = cor->x2;
		temp_z2 = cor->z2;
		cor->x1 = temp_x1 * cos(data->dec_y) + temp_z1 * sin(data->dec_y);
		cor->z1 = temp_x1 * sin(data->dec_y) + temp_z1 * cos(data->dec_y);
		cor->x2 = temp_x2 * cos(data->dec_y) + temp_z2 * sin(data->dec_y);
		cor->z2 = temp_x2 * sin(data->dec_y) + temp_z2 * cos(data->dec_y);
	}
}

void		ft_rotate_z(t_handle *data, t_cor *cor)
{
	float	temp_x1;
	float	temp_y1;
	float	temp_x2;
	float	temp_y2;

	if (data->dec_z)
	{
		temp_x1 = cor->x1;
		temp_y1 = cor->y1;
		temp_x2 = cor->x2;
		temp_y2 = cor->y2;
		cor->x1 = temp_x1 * cos(data->dec_z) - temp_y1 * sin(data->dec_z);
		cor->x2 = temp_x2 * cos(data->dec_z) - temp_y2 * sin(data->dec_z);
		cor->y1 = -temp_x1 * sin(data->dec_z) + temp_y1 * cos(data->dec_z);
		cor->y2 = -temp_x2 * sin(data->dec_z) + temp_y2 * cos(data->dec_z);
	}
}

t_cor		ft_blank(t_handle *data, t_map *map1, t_map *map2)
{
	t_cor	cor;

	cor.x1 = data->shiftx + map1->x * data->zoom;
	cor.x2 = data->shiftx + map2->x * data->zoom;
	cor.y1 = data->shifty + map1->y * data->zoom;
	cor.y2 = data->shifty + map2->y * data->zoom;
	cor.z1 = map1->z * data->h;
	cor.z2 = map2->z * data->h;
	cor.color1 = map1->color;
	cor.color2 = map2->color;
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	ft_rotate_z(data, &cor);
	return (cor);
}
