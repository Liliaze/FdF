/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:42:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/18 18:07:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, void *param)
{
	printf("key = %d\n", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (1);
}

int	main(int ac, char **av)
{
	t_win	win;
	t_form	form;

	win.h = 300;
	win.w = 300;
	form.h = 50;
	form.w = 50;
	form.x = 100;
	form.y = 100;
	form.t = 10;
	form.color = RED;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.h, win.w, "Test recup new_image");
	draw_carre(&win, &form);
	mlx_key_hook(win.win, close_win, 0);
	mlx_loop(win.mlx);
	return (0);
}
