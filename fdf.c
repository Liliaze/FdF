/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:42:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/19 18:05:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	close_win(int keycode, t_win *win)
{
	printf("key = %d\n", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (1);
}

void	init_shape(t_win *win, t_shape *shape)
{
	win->h = 300;
	win->w = 300;
	shape->h = 150;
	shape->w = 150;
	shape->x = (win->w - shape->w) / 2;
	shape->y = (win->h - shape->h) / 2;
	shape->t = 5;
	shape->color = PINK;
}


int	main(int ac, char **av)
{
	t_win	win;
	t_shape	shape;

	if (ac > 1)
	{
		printf("test av %s\n", av[1]);
	}
	win.mlx = mlx_init();
	init_shape(&win, &shape);
	win.win = mlx_new_window(win.mlx, win.h, win.w, "Test recup new_image");
	draw_carre(&win, &shape);
	draw_arc(&win, &shape);
	mlx_key_hook(win.win, close_win, &win);
	mlx_loop(win.mlx);
	return (0);
}
