/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 04:55:36 by romarash          #+#    #+#             */
/*   Updated: 2020/02/14 15:48:40 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_save_map(int fd, char *buf, t_map *map, t_handle *data)
{
	char	**split;
	char	**part;
	int		j;

	while (get_next_line(fd, &buf) == 1)
	{
		split = ft_strsplit(buf, ' ');
		j = 0;
		while (split[j] != NULL)
		{
			part = ft_strsplit(split[j], ',');
			if ((!(map->next = ft_lstnews()) || (ft_isdigite(part[0]) == 0)))
				return (0);
			map = ft_fill_map(j++, data, part, map);
			if (j > data->wid && data->hei != 0)
				break ;
		}
		if (ft_check_wei(split, data->wid) == 0)
			return (0);
		data->hei++;
		ft_free_arr(split);
		ft_null_free(buf);
	}
	ft_null_free(buf);
	return (1);
}

t_map	*ft_open_arg(char *av, t_handle *data)
{
	int		fd;
	t_map	*map;
	t_map	*head;
	char	*buf;

	buf = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (NULL);
	if ((read(fd, NULL, 0)) < 0)
		return (NULL);
	if (!(head = ft_lstnews()))
		return (NULL);
	map = head;
	if (!(ft_save_map(fd, buf, map, data)))
		return (NULL);
	ft_filler(data, 0);
	data->mlx_ptr = mlx_init();
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "YOL_63");
	data->draw = mlx_get_data_addr(data->img, &data->bits,
			&data->size, &data->endian);
	return (head);
}

int		deal_key(int key, t_handle *data)
{
	if (key == 82)
		ft_filler(data, 0);
	if (key == 87)
		ft_filler(data, 1);
	if (key == 83)
		ft_filler(data, 2);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data->map, data);
	return (1);
}

int		deal_hook(int key, t_handle *data)
{
	if (key >= 65 && key <= 92)
		ft_num_keys(key, data);
	if (key == 125)
		data->h = data->h - 0.5;
	if (key == 126)
		data->h = data->h + 0.5;
	if (key == 6)
		data->dec_x += 0.05;
	if (key == 7)
		data->dec_y += 0.05;
	if (key == 8)
		data->dec_z += 0.05;
	if (key == 0)
		data->dec_x -= 0.05;
	if (key == 1)
		data->dec_y -= 0.05;
	if (key == 2)
		data->dec_z -= 0.05;
//	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
//	data->draw = mlx_get_data_addr(data->img, &data->bits,
//	&data->size, &data->endian);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data->map, data);
	return (1);
}

void	ft_filler(t_handle *data, int flag)
{
	data->shiftx = 500;
	data->shifty = 500;
	data->zoom = 10;
	data->h = 1;
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

int		main(int ac, char **av)
{
	t_map		*fdf;
	t_handle	data;

	if (ac != 2)
		ft_error(1);
	ft_bzero(&data, sizeof(t_handle));
	if (!(fdf = ft_open_arg(av[1], &data)))
		ft_error(2);
	data.map = fdf;
	ft_filler(&data, 0);
	ft_draw(fdf, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
//	mlx_hook(data.win_ptr, 1L<<0, mouse_test, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, deal_hook, &data);
	mlx_mouse_hook(data.win_ptr, ft_mouse_key, &data);
	mlx_loop(data.mlx_ptr);
	ft_lstdels(&fdf);
	return (0);
}
