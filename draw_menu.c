/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:59:19 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 15:40:05 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_arc(t_all *all)
{
	int	y;
	int	x;
	int	d;
	int	e;
	int	gap;

	d = MAPW * 0.18;
	e = (MAPW - 2 * d) / 2;
	y = d * 0.95;
	while (--y > 0)
	{
		x = d * 2;
		while (--x > 0)
		{
			gap = (d - x) * (d - x) + (d - y) * (d - y);
			if (gap < d * d * 0.5 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, BLUEF);
			else if (gap < d * d * 0.6 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, GREENF);
			else if (gap < d * d * 0.7 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, ORANGE);
			else if (gap < d * d * 0.8 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, RED);
		}
	}
}

static void	draw_background(t_all *all)
{
	int		y;
	int		x;
	int		d;

	d = MAPW / 8;
	y = -1;
	while (++y < MAPH)
	{
		x = -1;
		while (++x < MAPW)
		{
			if (((x < MAPW / 12 || x > MAPW - MAPW / 12) ||
					(y < MAPH / 12 || y > MAPH - MAPH / 12)) && y < MAPH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) * y / 2);
			else if (((x < MAPW / 12 || x > MAPW - MAPW / 12) ||
					(y < MAPH / 12 || y > MAPH - MAPH / 12)) && y > MAPH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) / y);
		}
	}
}

static void	draw_str_menu(t_all *all)
{
	char	*enter;
	int		i;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	i = 1;
	enter = "Please enter the NUMBER of the map you want to launch.";
	mlx_string_put(MLX, WIN, (MAPW - ft_strlen("WELCOME :D") * 10) / 2,
			(MAPH / 2) - 90, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (MAPW - ft_strlen(enter) * 10) / 2, MAPH / 2,
			RED, enter);
	while (NAME[i])
	{
		str = ft_itoa(i);
		tmp1 = ft_strjoin(" = ", NAME[i]);
		tmp2 = ft_strjoin(str, tmp1);
		mlx_string_put(MLX, WIN, (MAPW - (44 + ft_strlen(NAME[i]) * 10)) / 2,
				MAPH / 2 + 30 * i, GREEN, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
		ft_strdel(&str);
		i++;
	}
}

int			launch_menu(t_all *all)
{
	mlx_clear_window(MLX, WIN);
	draw_background(all);
	draw_arc(all);
	draw_str_menu(all);
	all->in_menu = 1;
	return (1);
}
