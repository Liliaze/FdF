/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:23:38 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 14:07:59 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	bres_dx_sup(t_all *all)
{
	int	i;
	int e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(MLX, WIN, all->apoint->x1, all->apoint->y1, COLOR);
	e = 2 * all->abres->dy - all->abres->dx;
	inc1 = 2 * (all->abres->dy - all->abres->dx);
	inc2 = 2 * all->abres->dy;
	while (i < all->abres->dx)
	{
		if (e >= 0)
		{
			all->apoint->y1 += all->abres->incy;
			e += inc1;
		}
		else
			e += inc2;
		all->apoint->x1 += all->abres->incx;
		mlx_pixel_put(MLX, WIN, all->apoint->x1, all->apoint->y1, COLOR);
		i++;
	}
}

static void		bres_else(t_all *all)
{
	int	i;
	int	e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(MLX, WIN, all->apoint->x1, all->apoint->y1, COLOR);
	e = 2 * all->abres->dx - all->abres->dy;
	inc1 = 2 * (all->abres->dx - all->abres->dy);
	inc2 = 2 * all->abres->dx;
	while (i < all->abres->dy)
	{
		if (e >= 0)
		{
			all->apoint->x1 += all->abres->incx;
			e += inc1;
		}
		else
			e += inc2;
		all->apoint->y1 += all->abres->incy;
		mlx_pixel_put(MLX, WIN, all->apoint->x1, all->apoint->y1, COLOR);
		i++;
	}
}

int				bres(t_all *all)
{
	all->abres->dx = all->apoint->x2 - all->apoint->x1;
	all->abres->dy = all->apoint->y2 - all->apoint->y1;
	if (all->abres->dx < 0)
		all->abres->dx = -all->abres->dx;
	if (all->abres->dy < 0)
		all->abres->dy = -all->abres->dy;
	all->abres->incx = 1;
	if (all->apoint->x2 < all->apoint->x1)
		all->abres->incx = -1;
	all->abres->incy = 1;
	if (all->apoint->y2 < all->apoint->y1)
		all->abres->incy = -1;
	if (all->abres->dx > all->abres->dy)
		bres_dx_sup(all);
	else
		bres_else(all);
	return (0);
}
