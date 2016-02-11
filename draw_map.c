/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:06:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 17:19:51 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	choose_color(t_all *all, int z, int z_next)
{
	if (z_next == 0 && z == 0)
		COLOR = GREENF;
	else if (z == ZMAX && z_next == ZMAX)
		COLOR = RED;
	else if (z == ZMIN && z_next == ZMIN)
		COLOR = BLUEF;
	else if (z >= ZMAX / 2 || z_next >= ZMAX / 2)
		COLOR = PINK;
	else if (z >= 0 && z_next >= 0)
		COLOR = ORANGE;
	else if (z >= ZMIN / 2 || z_next >= ZMIN / 2)
		COLOR = CYAN;
	else if (z >= ZMIN || z_next >= ZMIN)
		COLOR = BLUE;
}

static void	draw_point_y(t_all *all)
{
	int		x;
	int		y;
	float	tmp_x1;
	float	tmp_y1;
	float	tmp_y2;

	y = -1;
	tmp_y1 = ECART;
	while (MAP[++y] && MAP[y + 1])
	{
		x = -1;
		tmp_y2 = tmp_y1 + ECART;
		while (MAP[y][++x] && MAP[y + 1][x])
		{
			tmp_x1 = x * ECART + ECART;
			all->apoint->x1 = (tmp_x1 - tmp_y1) + SW;
			all->apoint->x2 = (tmp_x1 - tmp_y2) + SW;
			all->apoint->y1 = ((tmp_x1 + tmp_y1) / 2 + SH) * COEFY - Z1;
			all->apoint->y2 = ((tmp_x1 + tmp_y2) / 2 + SH) * COEFY - Z2Y;
			choose_color(all, Z1, Z2Y);
			bres(all);
		}
		tmp_y1 = tmp_y2;
	}
}

static void	draw_point_x(t_all *all)
{
	int		x;
	int		y;
	float	tmp_x1;
	float	tmp_x2;
	float	tmp_y1;

	y = -1;
	while (MAP[++y])
	{
		x = -1;
		tmp_x1 = ECART;
		while (MAP[y][++x] && MAP[y][x + 1])
		{
			tmp_x2 = tmp_x1 + ECART;
			tmp_y1 = y * ECART + ECART;
			all->apoint->x1 = (tmp_x1 - tmp_y1) + SW;
			all->apoint->x2 = (tmp_x2 - tmp_y1) + SW;
			all->apoint->y1 = ((tmp_x1 + tmp_y1) / 2 + SH) * COEFY - Z1;
			all->apoint->y2 = ((tmp_x2 + tmp_y1) / 2 + SH) * COEFY - Z2X;
			choose_color(all, Z1, Z2X);
			bres(all);
			tmp_x1 = tmp_x2;
		}
	}
}

int			draw_map(t_all *all)
{
	char	*legende1;
	char	*legende2;

	legende1 = "ESC to quit || ENTER to return Menu || DEL to delete";
	legende2 = "'-' or '+' to zoom || 'W-A-S-D' to move || UP and DOWN \
				to change Z || 'Q-E-LEFT-RIGHT' to incline Y";
	zmin_and_zmax(all);
	draw_point_y(all);
	draw_point_x(all);
	mlx_string_put(MLX, WIN, (MAPW - ft_strlen(legende1) * 11) / 2,
			MAPH - 60, YELLOW, legende1);
	mlx_string_put(MLX, WIN, (MAPW - ft_strlen(legende2) * 11) / 2,
			MAPH - 30, YELLOW, legende2);
	return (1);
}
