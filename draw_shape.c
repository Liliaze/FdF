/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:27:10 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/19 18:04:54 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		draw_carre(t_win *win, t_shape *sh)
{
	int	i;
	int	i2;

	i = sh->y;
	while (i < sh->h + sh->y)
	{
		i2 = sh->x;
		while (i2 < sh->w + sh->x)
		{
			if (!(i > sh->y + sh->t && i < sh->y + sh->h - sh->t &&
					i2 > sh->x + sh->t && i2 < sh->x + sh->w - sh->t))
				mlx_pixel_put(win->mlx, win->win, i2, i, sh->color);
			i2++;
		}
		i++;
	}
	return (1);
}

int		draw_arc(t_win *win, t_shape *sh)
{
	int 	r;
	int		y;
	int		x;
	int 	gap;

	r = sh->h/2;
	gap = 0;

	y = sh->w/2;
	while (y > 0)
	{
		x = sh->h;
		while (x > 0)
		{
			if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.3))
				mlx_pixel_put(win->mlx, win->win, x, y, BLACK);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.4))
				mlx_pixel_put(win->mlx, win->win, x, y, BLUE);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.5))
				mlx_pixel_put(win->mlx, win->win, x, y, CYAN);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.6))
				mlx_pixel_put(win->mlx, win->win, x, y, YELLOW);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.7))
				mlx_pixel_put(win->mlx, win->win, x, y, GREEN);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.8))
				mlx_pixel_put(win->mlx, win->win, x, y, PINK);
			else if ((gap = ((sh->x - x) * (sh->x - x) + (sh->y - y) * (sh->y - y)) < (r * r) * 0.9))
				mlx_pixel_put(win->mlx, win->win, x, y, RED);
			x--;
		}
		y--;
	}
	return (1);
}
