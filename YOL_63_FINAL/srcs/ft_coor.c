/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:56:28 by aophion           #+#    #+#             */
/*   Updated: 2020/02/17 19:28:49 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor		ft_isom(t_handle *data, t_cor *prev)
{
	t_cor	cor;
	float	temp_y1;
	float	temp_y2;
	float	temp_x1;
	float	temp_x2;

	cor = *prev;
	ft_rotate_z(data, &cor);
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	temp_y1 = cor.y1;
	temp_y2 = cor.y2;
	temp_x1 = cor.x1;
	temp_x2 = cor.x2;
	cor.x1 = data->shiftx + ((temp_x1 - temp_y1) * cos(data->rad)) * data->zoom;
	cor.x2 = data->shiftx + ((temp_x2 - temp_y2) * cos(data->rad)) * data->zoom;
	cor.y1 = data->shifty + ((temp_x1 + temp_y1) * sin(data->rad)
			- cor.z1) * data->zoom;
	cor.y2 = data->shifty + ((temp_x2 + temp_y2) * sin(data->rad)
			- cor.z2) * data->zoom;
	cor.z1 = cor.z1;
	cor.z2 = cor.z2;
	return (cor);
}

void		ft_rotate_x(t_handle *data, t_cor *cor)
{
	float	temp_y1;
	float	temp_y2;

	temp_y1 = cor->y1;
	temp_y2 = cor->y2;
	cor->y1 = temp_y1 * cos(data->dec_x) + cor->z1 * sin(data->dec_x);
	cor->z1 = -temp_y1 * sin(data->dec_x) + cor->z1 * cos(data->dec_x);
	cor->y2 = temp_y2 * cos(data->dec_x) + cor->z2 * sin(data->dec_x);
	cor->z2 = -temp_y2 * sin(data->dec_x) + cor->z2 * cos(data->dec_x);
}

void		ft_rotate_y(t_handle *data, t_cor *cor)
{
	float	temp_x1;
	float	temp_x2;

	temp_x1 = cor->x1;
	temp_x2 = cor->x2;
	cor->x1 = temp_x1 * cos(data->dec_y) + cor->z1 * sin(data->dec_y);
	cor->z1 = -temp_x1 * sin(data->dec_y) + cor->z1 * cos(data->dec_y);
	cor->x2 = temp_x2 * cos(data->dec_y) + cor->z2 * sin(data->dec_y);
	cor->z2 = -temp_x2 * sin(data->dec_y) + cor->z2 * cos(data->dec_y);
}

void		ft_rotate_z(t_handle *data, t_cor *cor)
{
	float	temp_x1;
	float	temp_x2;

	temp_x1 = cor->x1;
	temp_x2 = cor->x2;
	cor->x1 = temp_x1 * cos(data->dec_z) - cor->y1 * sin(data->dec_z);
	cor->y1 = temp_x1 * sin(data->dec_z) + cor->y1 * cos(data->dec_z);
	cor->x2 = temp_x2 * cos(data->dec_z) - cor->y2 * sin(data->dec_z);
	cor->y2 = temp_x2 * sin(data->dec_z) + cor->y2 * cos(data->dec_z);
}

t_cor		ft_blank1(t_handle *data, t_cor *prev)
{
	t_cor	cor;

	cor = *prev;
	ft_rotate_z(data, &cor);
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	cor.x1 = data->shiftx + cor.x1 * data->zoom;
	cor.x2 = data->shiftx + cor.x2 * data->zoom;
	cor.y1 = data->shifty + cor.y1 * data->zoom;
	cor.y2 = data->shifty + cor.y2 * data->zoom;
	cor.z1 = cor.z1;
	cor.z2 = cor.z2;
	return (cor);
}
