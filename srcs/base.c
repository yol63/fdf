/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:03:11 by aophion           #+#    #+#             */
/*   Updated: 2020/02/20 16:33:14 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_check(const char *str, int *flag)
{
	size_t i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '0')
		i++;
	else
		ft_error(2, "color is invalid\n");
	if (str[i] == 'x')
		i++;
	else
		ft_error(2, "color is invalid\n");
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*flag = 1;
		i++;
	}
	return (i);
}

static int		ft_res(long int res, char *str, int base, size_t i)
{
	if (str[i] >= 48 && str[i] <= 57)
		res = res * base + (long int)(str[i] - 48);
	else if (str[i] >= 97 && str[i] <= 102)
		res = res * base + (long int)(str[i] - 87);
	else
		res = res * base + (long int)(str[i] - 55);
	return (res);
}

int				ft_atoi_base(char *str, int base)
{
	int		res;
	size_t	i;
	int		flag;

	i = 0;
	res = 0;
	flag = 0;
	if (!str)
		return (-1);
	i = ft_check(str, &flag);
	while (((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70)
		|| (str[i] >= 97 && str[i] <= 102)) && (i <= 7))
	{
		res = ft_res(res, str, base, i);
		i++;
	}
	if (str[i] != '\0')
		ft_error(2, "color is invalid\n");
	if (flag == 1)
		return (res * (-1));
	return (res);
}

void			ft_z_color(t_handle *data, t_map *map1, t_map *map2, t_cor *cor)
{
	if (map1->color == -1)
	{
		if (data->colorflag == 0)
			cor->color1 = 0xffffff;
		else if (map1->z < (data->maxz / 3))
			cor->color1 = 0x0000ff;
		else if (map1->z > 2 * (data->maxz / 3))
			cor->color1 = 0xff0000;
		else
			cor->color1 = 0x00ff00;
	}
	if (map2->color == -1)
	{
		if (data->colorflag == 0)
			cor->color2 = 0xffffff;
		else if (map2->z < (data->maxz / 3))
			cor->color2 = 0x0000ff;
		else if (map2->z > 2 * (data->maxz / 3))
			cor->color2 = 0xff0000;
		else
			cor->color2 = 0x00ff00;
	}
	cor->colour = cor->color1;
}
