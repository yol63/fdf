/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:39:19 by romarash          #+#    #+#             */
/*   Updated: 2020/02/17 19:32:08 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_isdigite(char *ch)
{
	size_t i;

	i = 0;
	while (ch[i] != '\0')
	{
		if ((ch[i] < 48 || ch[i] > 57) && (ch[i] != 45) && (ch[i] != 43))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_wei(char **split, int wid)
{
	int i;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (wid > i - 1)
		return (0);
	return (1);
}

void	ft_filler(t_handle *data, int flag)
{
	data->shiftx = 500;
	data->shifty = 500;
	data->zoom = 10;
	data->h = 0.25;
	data->proj = flag;
	data->dec_x = 0;
	data->dec_y = 0;
	data->dec_z = 0;
	if (flag == 0)
		data->rad = 0.523599;
	if (flag == 1)
		data->rad = 0;
	if (flag == 2)
		data->rad = 1;
}

t_cor	ft_blank2(t_handle *data, t_cor *prev)
{
	t_cor	cor;

	cor = *prev;
	ft_rotate_z(data, &cor);
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	cor.x1 = data->shiftx + cor.x1 * data->zoom;
	cor.x2 = data->shiftx + cor.x2 * data->zoom;
	cor.y1 = data->shifty - cor.z1 * data->zoom;
	cor.y2 = data->shifty - cor.z2 * data->zoom;
	cor.z1 = cor.z1;
	cor.z2 = cor.z2;
	return (cor);
}

t_cor	ft_blank3(t_handle *data, t_cor *prev)
{
	t_cor	cor;

	cor = *prev;
	ft_rotate_z(data, &cor);
	ft_rotate_x(data, &cor);
	ft_rotate_y(data, &cor);
	cor.x1 = data->shiftx + cor.y1 * data->zoom;
	cor.x2 = data->shiftx + cor.y2 * data->zoom;
	cor.y1 = data->shifty - cor.z1 * data->zoom;
	cor.y2 = data->shifty - cor.z2 * data->zoom;
	cor.z1 = cor.z1;
	cor.z2 = cor.z2;
	return (cor);
}
