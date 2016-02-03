/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:51:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/03 13:54:39 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	init_size_win(t_all	*all)
{
	all->awin->width = 640;
	all->awin->height = 480;
}

void	init_struct(t_all *all)
{
	all->apoint = (t_point *)ft_memalloc(sizeof(t_point));
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->amap = (t_map *)ft_memalloc(sizeof(t_map));
}

void	init_size_point(t_all *all)
{
	all->apoint->x1 = 250;
	all->apoint->y1 = 50;
	all->apoint->x2 = 10;
	all->apoint->y2 = 10;
}

int		main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	printf("malloc all is ok\n");
	init_struct(all);
	printf("init_struct is ok\n");
	if (argc == 2 && argv[1])
	{
		if ((all->awin->mlx = mlx_init()) == NULL)
			return (0);
		init_size_win(all);
	printf("init size win is ok\n");
		if ((all->awin->win = mlx_new_window(all->awin->mlx, all->awin->width, all->awin->height, "Hello world")) == NULL)
			return (0);
		//mlx_loop_hook(win.mlx);
		//mlx_clear_window(win.mlx, win.win);
		mlx_pixel_put(all->awin->mlx, all->awin->win, all->awin->width / 2, all->awin->height / 2, PINK);
		mlx_string_put(all->awin->mlx, all->awin->win, all->awin->width / 4, all->awin->height / 4, BLUE, "Hello world");
		init_size_point(all);
	printf("init size point is ok\n");
		bres(all);
		//win.image = mlx_new_image(win.mlx, win.width, win.height);
		//mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
		all->amap->name = argv[1];
		open_map(all);
		mlx_key_hook(all->awin->win, key_press, all);
		mlx_loop(all->awin->mlx);
	}
	return (0);
}
