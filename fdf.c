/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 04:55:36 by romarash          #+#    #+#             */
/*   Updated: 2020/02/04 05:06:26 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int error)
{
	if (error == 1)
		ft_putstr("usage: ./fdf map.fdf\n");
	if (error == 2)
		ft_putstr("error\n");
	exit(1);
}

t_fdf	*ft_save_map(char *map, fd)
{
	fdf	*map;

	return (map);
}

int		main(int argc, char **argv)
{
	int		rd;
	t_fdf	*fdf;

	if (argc != 2)
		ft_error(1);
	if ((fd = open (argv[1],O_RDONLY)) < 0)
		ft_error(2);
	fdf = ft_save_map(argv[1]);
	
	return (0);
}
