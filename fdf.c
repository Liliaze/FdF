/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:42:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/20 18:53:31 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	segment(t_win *win, t_map *map)
{
	float	dx;
	float	dy;
	float	coef;
	int		but;
	int		i;

	dx = map->bx - map->ax;
	printf("bx = %d, ax = %d donc dx = %f.\n", map->bx, map->ax, dx);
	dy = map->by - map->ay;
	printf("by = %d, ay = %d donc dy = %f.\n", map->by, map->ay, dy);
	coef = dy / dx;
	printf("coef = %f\n", coef);
	if (map->bx > map->ax)
		but = map->ay;
	else if (map->bx < map->ax)
		but = map->by;
	i = 0;
	while (i <= map->bx || i <= map->ax)
	{
		if (dx == 0 && map->bx > map->ax)
			mlx_pixel_put(win->mlx, win->win, map->ax, round(map->ax + i), GREEN);
		else if (dy == 0 && map->bx < map->ax)
		{mlx_pixel_put(win->mlx, win->win, map->ax, round(map->ax + i), GREEN);
		printf("sup- i = %d, round1 = %f, round 2 = %d\n", i, round(map->ax + i), map->ay);}
		else if (map->bx > map->ax)
		{mlx_pixel_put(win->mlx, win->win, round(map->ax + i), round(coef * i + but) , GREEN);
		printf("sup- i = %d, round1 = %f, round 2 = %f\n", i, round(map->ax + i), round(coef * i + but));}
		else if (map->bx < map->ax)
		{mlx_pixel_put(win->mlx, win->win, round(map->bx + i), round(coef * i - but) , GREEN);
		printf("inf- i = %d, round1 = %f, round 2 = %f\n", i, round(map->bx + i), round(coef * i - but));}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_win	win;
	t_shape	shape;
	int		ret;

	ret = 1;
	if (ac > 1)
	{
		printf("test av %s\n", av[1]);
	}
	win.mlx = mlx_init();
	win.h = 300;
	win.w = 300;
	win.win = mlx_new_window(win.mlx, win.h, win.w, "Test recup new_image");
	init_shape(&win, &shape);
	map.ax = 150;
	map.ay = 300;
	map.bx = 150;
	map.by = 200;
	segment(&win, &map);
	mlx_key_hook(win.win, close_win, &shape);
	mlx_loop(win.mlx);
	return (0);
}
