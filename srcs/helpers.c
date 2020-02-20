/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aophion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:55:54 by aophion           #+#    #+#             */
/*   Updated: 2020/02/20 16:33:09 by aophion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(int exit_code, char *message)
{
	ft_putstr_fd(message, exit_code);
	exit(exit_code);
}

t_map		*ft_lstnews(void)
{
	t_map	*newlist;

	if (!(newlist = malloc(sizeof(t_map))))
		return (NULL);
	ft_bzero(newlist, sizeof(t_map));
	newlist->x = -1;
	newlist->y = 0;
	newlist->z = 0;
	newlist->next = NULL;
	return (newlist);
}

void		ft_lstdels(t_map **alst)
{
	t_map	*list;

	if (alst)
	{
		while (*alst)
		{
			list = (*alst)->next;
			free(*alst);
			*alst = list;
		}
		free(*alst);
		*alst = NULL;
	}
}

void		ft_null_free(char *buf)
{
	free(buf);
	buf = NULL;
}

t_map		*ft_fill_map(int x, t_handle *data, char **split, t_map *map)
{
	map->x = x;
	map->y = data->hei;
	if (data->wid < map->x && data->hei == 0)
		data->wid = map->x;
	map->z = ft_realatoi(split[0]);
	if (data->maxz < map->z)
		data->maxz = map->z;
	map->color = ft_atoi_base(split[1], 16);
	ft_free_arr(split);
	return (map->next);
}
