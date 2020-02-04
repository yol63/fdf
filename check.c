/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:19:49 by romarash          #+#    #+#             */
/*   Updated: 2020/02/04 05:42:49 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	int j = 50;
	int i = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000,1000, "YOL_63");
	while (i < 950)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i ,j ,0x452587);
		i++;
		j++;
	}
	mlx_loop(mlx_ptr);
	return (0);

}
