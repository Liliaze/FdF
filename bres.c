/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:23:38 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/03 12:48:18 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	bres_dx_sup(t_all *all, int dx, int dy, int incx, int incy)
{
	int	i;
	int e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(all->awin->mlx, all->awin->win, all->apoint->x1,
			all->apoint->y1, CYAN);
	e = 2 * dy - dx;
	inc1 = 2 * (dy - dx);
	inc2 = 2 * dy;
	while (i < dx)
	{
		if (e >= 0)
		{
			all->apoint->y1 += incy;
			e += inc1;
		}
		else
			e += inc2;
		all->apoint->x1 += incx;
		mlx_pixel_put(all->awin->mlx, all->awin->win, all->apoint->x1,
				all->apoint->y1, CYAN);
		i++;
	}
}

static void		bres_else(t_all *all, int dx, int dy, int incx, int incy)
{
	int	i;
	int	e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(all->awin->mlx, all->awin->win, all->apoint->x1,
			all->apoint->y1, CYAN);
	e = 2 * dx - dy;
	inc1 = 2 * (dx - dy);
	inc2 = 2 * dx;
	while (i < dy)
	{
		if (e >= 0)
		{
			all->apoint->x1 += incx;
			e += inc1;
		}
		else
			e += inc2;
		all->apoint->y1 += incy;
		mlx_pixel_put(all->awin->mlx, all->awin->win, all->apoint->x1,
				all->apoint->y1, CYAN);
		i++;
	}
}

int				bres(t_all *all)
{
	int	dx;
	int dy;
	int incx;
	int incy;

	dx = all->apoint->x2 - all->apoint->x1;
	dy = all->apoint->y2 - all->apoint->y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	incx = 1;
	if (all->apoint->x2 < all->apoint->x1)
		incx = -1;
	incy = 1;
	if (all->apoint->y2 < all->apoint->y1)
		incy = -1;
	if (dx > dy)
		bres_dx_sup(all, dx, dy, incx, incy);
	else
		bres_else(all, dx, dy, incx, incy);
	return (0);
}
