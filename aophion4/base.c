/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:03:11 by aophion           #+#    #+#             */
/*   Updated: 2020/02/15 14:24:26 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_check(const char *str, int *flag)
{
	size_t i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '0' || str[i] == 'x')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*flag = 1;
		i++;
	}
	return (i);
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
		return (0);
	i = ft_check(str, &flag);
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70)
		|| (str[i] >= 97 && str[i] <= 102))
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70))
			res = res * base + (long int)(str[i] - 48);
		else
			res = res * base + (long int)(str[i] - 80);
		i++;
	}
	if (str[i] != '\0')
		ft_error(2);
	if (flag == 1)
		return (res * (-1));
	return (res);
}
