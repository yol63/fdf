/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:19:49 by romarash          #+#    #+#             */
/*   Updated: 2020/02/04 18:38:42 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float ft_abs(float n)
{
    if (n < 0)
        n = n * (-1);
    return (n);
}

void	ft_swap(float *a, float *b)
{
    float c;

    c = *a;
    *a = *b;
    *b = c;
}

float ft_max(float a, float b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

void wr_linex(void *mlx_ptr, void *win_ptr, t_map *map1, t_map *map2)
{
    float x1 = 0;
	float x2 = 0;
    float y1 = 0;
    float y2 = 0;
  //  int i = 0;
    float shag1 = 0;
    float shag2 = 0;
    float abs1;
    float abs2;


    x1 = 400.00 + ((map1->x - map1->y) * cos(0.523599)) * 20.00;
    x2 = 400.00 + ((map2->x - map2->y) * cos(0.523599)) * 20.00;
    y1 = 400.00 + ((map1->x + map1->y) * sin(0.523599) - (map1->z)) * 20.00;
    y2 = 400.00 + ((map2->x + map2->y) * sin(0.523599) - (map2->z)) * 20.00;



/*
    x1 = 5.00 + (float)(map1->x) * 100.00;
    x2 = 5.00 + (float)(map2->x) * 100.00;
    y1 = 5.00 + (float)(map1->y) * 100.00;
    y2 = 5.00 + (float)(map2->y) * 100.00;
    */

    abs1 = ft_abs(x2 - x1);
    abs2 = ft_abs(y2 - y1);

    shag1 = (x2 - x1) / (ft_max(abs1, abs2));
    shag2 = (y2 - y1) / (ft_max(abs1, abs2));

      // if (x2 < x1)
      //     ft_swap(&x2, &x1);
      // if (y2 < y1)
      //     ft_swap(&y2, &y1);


       while (ft_abs((int)(y2 - y1))  != 0 || ft_abs((int)(x2 - x1)) != 0 )
       {
           if (map1->z > 2 || map2->z > 2)
            mlx_pixel_put(mlx_ptr, win_ptr, x1 ,y1 ,0xFFFFF);
           else
               mlx_pixel_put(mlx_ptr, win_ptr, x1 ,y1 ,0xFFFFFF);
           x1 = x1 + shag1;
           y1 = y1 + shag2;
           //i++;
       }
   }

   int ft_draw(t_map *start)
   {
       void	*mlx_ptr;
       void	*win_ptr;
       t_map   *map1 = start;
       t_map   *tmp = start;
       t_map   *map2 = NULL;

       mlx_ptr = mlx_init();
       win_ptr = mlx_new_window(mlx_ptr, 2000,2000, "YOL_63");
       while(start->next)
       {
           tmp = start;
           while(tmp->next!= NULL)
           {
               if ((tmp->x == (start->x + 1)) && (tmp->y == start->y))
                   map1 = tmp;
               if ((tmp->x == start->x) && (tmp->y == (start->y + 1)))
               {
                   map2 = tmp;
                   break;
               }
               tmp = tmp->next;
           }
           if (map1 != NULL)
               wr_linex(mlx_ptr, win_ptr, start, map1);
           if (map2 != NULL)
               wr_linex(mlx_ptr, win_ptr, start, map2);
           //wr_linex(mlx_ptr, win_ptr, map1, map2);
           start = start->next;
           map2 = NULL;
           map1 = NULL;
       }
       mlx_loop(mlx_ptr);
       return (0);
   }
