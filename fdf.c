/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 04:55:36 by romarash          #+#    #+#             */
/*   Updated: 2020/02/05 20:11:12 by romarash         ###   ########.fr       */
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

t_map	*ft_lstnews(void)
{
    t_map	*newlist;

    if (!(newlist = malloc(sizeof(t_map))))
        return (NULL);
    newlist->next = NULL;
    return (newlist);
}

t_map	*ft_save_map(int fd)
{
	t_map   *start;
    t_map	*map;
	char	*buf;
	char    **split;
	int		i = 0;
	int		j = 0;

	buf = NULL;
	start = ft_lstnews();
	map = start;
	while (get_next_line(fd, &buf) == 1)
	{
		split = ft_strsplit(buf, ' ');
	    j = 0;
		while (split[j] != NULL)
		{
		    map->x = j;
            map->y = i;
            map->z = ft_atoi(split[j]);
            j++;
            map->next = ft_lstnews();
			map = map->next;
        }
		i++;
		ft_free_arr(split);
		free(buf);
		buf = NULL;
	}
	free(buf);
	buf = NULL;
	return (start);
}

void			ft_lstdels(t_map **alst)
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

void ft_write(t_map* map)
{
    while(map->next != NULL)
    {
        ft_putstr("x = ");
        ft_putnbr(map->x);
        ft_putchar (' ');
        ft_putstr("y = ");
        ft_putnbr(map->y);
        ft_putchar (' ');
        ft_putstr("z = ");
        ft_putnbr(map->z);
        ft_putchar ('\n');
        map = map->next;
		}
}

int		main(int argc, char **argv)
{
	int 	fd;
	t_map	*fdf;

	if (argc != 2)
		ft_error(1);
	if ((fd = open (argv[1],O_RDONLY)) < 0)
		ft_error(2);
	fdf = ft_save_map(fd);
	if (!fdf)
	    ft_error(2);
	ft_write(fdf);
    ft_draw(fdf);
	ft_lstdels(&fdf);
	return (0);
}
