/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:27:10 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/18 18:09:05 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_carre(t_win *win, t_form *form)
{
	int	i;
	int	i2;

	i = form->y;
	while (i < form->h + form->y)
	{
		i2 = form->x;
		while (i2 < form->w + form->x)
		{
			if (i > form->y + form->t && i < form->y + form->h - form->t &&
					i2 > form->x + form->t && i2 < form->x + form->w - form->t)
				printf("hey no en i = %d et i2 =%d\n", i, i2);
			else
				mlx_pixel_put(win->mlx, win->win, i2, i, form->color);
			i2++;
		}
		i++;
	}
	return (1);
}
/*
int	draw_arc_en_ciel(char *mlx, char *win, int x, int y)
{
	int 	r;
	int 	ecart;
	int		centre_x;
	int		xx;
	int		centre_y;

	r = x / 3;
	ecart = 0;
	centre_x = x / 2;
	centre_y = y / 2;
	xx = x;

	y = y / 2;
	while (y > 0)
	{
		x = xx;
		while (x > 0)
		{
			if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.3))
				mlx_pixel_put(mlx, win, x, y, 0x000000);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.4))
				mlx_pixel_put(mlx, win, x, y, 0xDD22DD);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.5))
				mlx_pixel_put(mlx, win, x, y, 0x11AAFF);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.6))
				mlx_pixel_put(mlx, win, x, y, 0x00FF33);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.7))
				mlx_pixel_put(mlx, win, x, y, 0xEEEE11);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.8))
				mlx_pixel_put(mlx, win, x, y, 0xFFBB00);
			else if ((ecart = ((centre_x - x) * (centre_x - x) + (centre_y - y) * (centre_y - y)) < (r * r) * 0.9))
				mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x--;
		}
		y--;
	}
	return (1);
}
*/
