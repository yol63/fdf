/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:36:44 by aophion           #+#    #+#             */
/*   Updated: 2020/02/20 14:22:26 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_cor *cor, double del_x, double del_y, double max)
{
	t_bit	bit;
	double	step;

	if (ft_abs(del_x) > ft_abs(del_y))
		step = (cor->x1 - cor->x0) / (del_x > 0 ? max : -max);
	else
		step = (cor->y1 - cor->y0) / (del_y > 0 ? max : -max);
	bit.red_1 = ((cor->colour >> 16L) & 255) * (1 - step);
	bit.red_2 = ((cor->color2 >> 16L) & 255) * step;
	bit.greeb_1 = ((cor->colour >> 8L) & 255) * (1 - step);
	bit.greeb_2 = ((cor->color2 >> 8L) & 255) * step;
	bit.blue_1 = (cor->colour & 255) * (1 - step);
	bit.blue_2 = (cor->color2 & 255) * step;
	bit.col = (bit.red_1 + bit.red_2) << 16L;
	bit.col |= (bit.greeb_1 + bit.greeb_2) << 8L;
	bit.col |= bit.blue_1 + bit.blue_2;
	return (bit.col);
}

int		ft_close(int key, int *i)
{
	key = 0;
	ft_error(*i, "Good night\n");
	return (0);
}
