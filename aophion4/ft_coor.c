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
    float	temp_y1;
    float	temp_z1;
    float	temp_y2;
    float	temp_z2;
    float	temp_x1;
    float	temp_x2;

    ft_bzero(&cor, sizeof(t_cor));
    cor.y1 = map1->y;
    cor.y2 = map2->y;
    cor.x1 = map1->x;
    cor.x2 = map2->x;
    cor.z1 = map1->z;
    cor.z2 = map2->z;
    ft_rotate_z(data, &cor, map1, map2);
    ft_rotate_x(data, &cor, map1, map2);
    ft_rotate_y(data, &cor, map1, map2);
    temp_y1 = cor.y1;
    temp_z1 = cor.z1;
    temp_y2 = cor.y2;
    temp_z2 = cor.z2;
    temp_x1 = cor.x1;
    temp_x2 = cor.x2;

	cor.x1 = data->shiftx + ((temp_x1 - temp_y1) * cos(data->rad)) * data->zoom;
	cor.x2 = data->shiftx + ((temp_x2 - temp_y2) * cos(data->rad)) * data->zoom;
	cor.y1 = data->shifty + ((temp_x1 + temp_y1) * sin(data->rad)
			- temp_z1 * data->h) * data->zoom;
	cor.y2 = data->shifty + ((temp_x2 + temp_y2) * sin(data->rad)
			- temp_z2 * data->h) * data->zoom;
	cor.z1 = temp_z1 * data->h;
	cor.z2 = temp_z2 * data->h;
	if (map1->color == 0)
		cor.color1 = 0xffffff;
	else
		cor.color1 = map1->color;
	if (map2->color == 0)
		cor.color2 = 0xffffff;
	else
		cor.color2 = map2->color;
//	ft_putstr("SUCCESS\n");
//	ft_rotate_x(data, &cor);
//	ft_rotate_y(data, &cor);
//	ft_rotate_z(data, &cor);
	return (cor);
}

void		ft_rotate_x(t_handle *data, t_cor *cor, t_map *map1, t_map *map2)
{
	float	temp_y1;
	float	temp_z1;
	float	temp_y2;
	float	temp_z2;

	//if (data->dec_x)
	//{
		temp_y1 = cor->y1;
		temp_z1 = cor->z1;
		temp_y2 = cor->y2;
		temp_z2 = cor->z2;

		cor->y1 = temp_y1 * cos(data->dec_x) + temp_z1 * sin(data->dec_x);
		cor->z1 = -temp_y1 * sin(data->dec_x) + temp_z1 * cos(data->dec_x);
		cor->y2 = temp_y2 * cos(data->dec_x) + temp_z2 * sin(data->dec_x);
		cor->z2 = -temp_y2 * sin(data->dec_x) + temp_z2 * cos(data->dec_x);
	//}
}

void		ft_rotate_y(t_handle *data, t_cor *cor, t_map *map1, t_map *map2)
{
	float	temp_x1;
	float	temp_z1;
	float	temp_x2;
	float	temp_z2;

	//if (data->dec_y)
	//{
		temp_x1 = cor->x1;
		temp_z1 = cor->z1;
		temp_x2 = cor->x2;
		temp_z2 = cor->z2;

		cor->x1 = temp_x1 * cos(data->dec_y) + temp_z1 * sin(data->dec_y);
		cor->z1 = -temp_x1 * sin(data->dec_y) + temp_z1 * cos(data->dec_y);
		cor->x2 = temp_x2 * cos(data->dec_y) + temp_z2 * sin(data->dec_y);
		cor->z2 = -temp_x2 * sin(data->dec_y) + temp_z2 * cos(data->dec_y);
	//}
}

void		ft_rotate_z(t_handle *data, t_cor *cor, t_map *map1, t_map *map2)
{
	float	temp_x1;
	float	temp_y1;
	float	temp_x2;
	float	temp_y2;

	//if (data->dec_z)
	//{
		temp_x1 = cor->x1;
		temp_y1 = cor->y1;
		temp_x2 = cor->x2;
		temp_y2 = cor->y2;

		cor->x1 = temp_x1 * cos(data->dec_z) - temp_y1 * sin(data->dec_z);
		cor->x2 = temp_x2 * cos(data->dec_z) - temp_y2 * sin(data->dec_z);
		cor->y1 = temp_x1 * sin(data->dec_z) + temp_y1 * cos(data->dec_z);
		cor->y2 = temp_x2 * sin(data->dec_z) + temp_y2 * cos(data->dec_z);
	//}
}

t_cor		ft_blank1(t_handle *data, t_map *map1, t_map *map2)
{
	t_cor	cor;

    float	temp_y1;
    float	temp_z1;
    float	temp_y2;
    float	temp_z2;
    float	temp_x1;
    float	temp_x2;

    ft_bzero(&cor, sizeof(t_cor));
    cor.y1 = map1->y;
    cor.y2 = map2->y;
    cor.x1 = map1->x;
    cor.x2 = map2->x;
    cor.z1 = map1->z;
    cor.z2 = map2->z;

    ft_rotate_z(data, &cor, map1, map2);
    ft_rotate_x(data, &cor, map1, map2);
    ft_rotate_y(data, &cor, map1, map2);

    temp_y1 = cor.y1;
    temp_z1 = cor.z1;
    temp_y2 = cor.y2;
    temp_z2 = cor.z2;
    temp_x1 = cor.x1;
    temp_x2 = cor.x2;

	cor.x1 = data->shiftx + temp_x1 * data->zoom;
	cor.x2 = data->shiftx + temp_x2 * data->zoom;
	cor.y1 = data->shifty + temp_y1 * data->zoom;
	cor.y2 = data->shifty + temp_y2 * data->zoom;
	cor.z1 = temp_z1 * data->h;
	cor.z2 = temp_z2 * data->h;
    if (map1->color == 0)
        cor.color1 = 0xffffff;
    else
        cor.color1 = map1->color;
    if (map2->color == 0)
        cor.color2 = 0xffffff;
    else
        cor.color2 = map2->color;
//	cor.color1 = map1->color;
//	cor.color2 = map2->color;
//	ft_rotate_x(data, &cor);
//	ft_rotate_y(data, &cor);
//	ft_rotate_z(data, &cor);
	return (cor);
}

t_cor		ft_blank2(t_handle *data, t_map *map1, t_map *map2)
{
    t_cor	cor;

    float	temp_y1;
    float	temp_z1;
    float	temp_y2;
    float	temp_z2;
    float	temp_x1;
    float	temp_x2;

    ft_bzero(&cor, sizeof(t_cor));
    cor.y1 = map1->y;
    cor.y2 = map2->y;
    cor.x1 = map1->x;
    cor.x2 = map2->x;
    cor.z1 = map1->z;
    cor.z2 = map2->z;

    ft_rotate_z(data, &cor, map1, map2);
    ft_rotate_x(data, &cor, map1, map2);
    ft_rotate_y(data, &cor, map1, map2);

    temp_y1 = cor.y1;
    temp_z1 = cor.z1;
    temp_y2 = cor.y2;
    temp_z2 = cor.z2;
    temp_x1 = cor.x1;
    temp_x2 = cor.x2;

    cor.x1 = data->shiftx + temp_x1 * data->zoom;
    cor.x2 = data->shiftx + temp_x2 * data->zoom;
    cor.y1 = data->shifty - temp_z1 * data->zoom  * data->h;
    cor.y2 = data->shifty - temp_z2 * data->zoom  * data->h;
    cor.z1 = temp_z1 * data->h;
    cor.z2 = temp_z2 * data->h;
    if (map1->color == 0)
        cor.color1 = 0xffffff;
    else
        cor.color1 = map1->color;
    if (map2->color == 0)
        cor.color2 = 0xffffff;
    else
        cor.color2 = map2->color;
//	cor.color1 = map1->color;
//	cor.color2 = map2->color;
//	ft_rotate_x(data, &cor);
//	ft_rotate_y(data, &cor);
//	ft_rotate_z(data, &cor);
    return (cor);
}

t_cor		ft_blank3(t_handle *data, t_map *map1, t_map *map2)
{
    t_cor	cor;

    float	temp_y1;
    float	temp_z1;
    float	temp_y2;
    float	temp_z2;
    float	temp_x1;
    float	temp_x2;

    ft_bzero(&cor, sizeof(t_cor));
    cor.y1 = map1->y;
    cor.y2 = map2->y;
    cor.x1 = map1->x;
    cor.x2 = map2->x;
    cor.z1 = map1->z;
    cor.z2 = map2->z;

    ft_rotate_z(data, &cor, map1, map2);
    ft_rotate_x(data, &cor, map1, map2);
    ft_rotate_y(data, &cor, map1, map2);

    temp_y1 = cor.y1;
    temp_z1 = cor.z1;
    temp_y2 = cor.y2;
    temp_z2 = cor.z2;
    temp_x1 = cor.x1;
    temp_x2 = cor.x2;

    cor.x1 = data->shiftx + temp_y1 * data->zoom;
    cor.x2 = data->shiftx + temp_y2 * data->zoom;
    cor.y1 = data->shifty - temp_z1 * data->zoom  * data->h;
    cor.y2 = data->shifty - temp_z2 * data->zoom  * data->h;
    cor.z1 = temp_z1 * data->h;
    cor.z2 = temp_z2 * data->h;
    if (map1->color == 0)
        cor.color1 = 0xffffff;
    else
        cor.color1 = map1->color;
    if (map2->color == 0)
        cor.color2 = 0xffffff;
    else
        cor.color2 = map2->color;
//	cor.color1 = map1->color;
//	cor.color2 = map2->color;
//	ft_rotate_x(data, &cor);
//	ft_rotate_y(data, &cor);
//	ft_rotate_z(data, &cor);
    return (cor);
}