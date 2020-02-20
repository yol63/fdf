/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raelatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:02:08 by romarash          #+#    #+#             */
/*   Updated: 2020/02/20 14:26:34 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t		ft_check(const char *str, int *flag)
{
	size_t i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*flag = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (i);
}

int					ft_realatoi(const char *str)
{
	long int	res;
	size_t		i;
	int			flag;

	i = 0;
	res = 0;
	flag = 0;
	i = ft_check(str, &flag);
	while (str[i] >= 48 && str[i] <= 57 && i <= 10)
	{
		res = res * 10 + (long int)(str[i] - 48);
		i++;
	}
	if ((flag == 1 && res > 2147483648) ||
			(flag == 0 && res > 2147483647) || i > 11)
		ft_error(1, "too big z coord\n");
	if (str[i] != '\0')
		ft_error(1, "z_coord is invalid\n");
	if (flag == 1)
		return ((int)(res * (-1)));
	return ((int)res);
}
