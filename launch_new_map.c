/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_new_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 09:59:28 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 14:12:55 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_to_name(t_all *all, int key)
{
	if (key <= 89 && key >= ONE)
		TNAME = NAME[key - 82];
	else if (key == 91 || key == NINE)
		TNAME = NAME[key - 83];
	else if (key == 23)
		TNAME = NAME[5];
	else if (key == 22)
		TNAME = NAME[6];
	else if (key == 28)
		TNAME = NAME[7];
	else if (key == 25)
		TNAME = NAME[8];
	else if (key == 36)
		TNAME = NAME[9];
	else
		TNAME = NAME[key - 17];
}

int			launch_new_map(t_all *all, int key)
{
	all->in_menu = 0;
	key_to_name(all, key);
	if (!open_map(all))
		return (0);
	if (all->amap->nb_y > all->amap->nb_x)
		ECART = (MAPH / all->amap->nb_y) / 1.5;
	else
		ECART = (MAPH / all->amap->nb_x) / 1.5;
	SW = (MAPW - all->amap->nb_x * (ECART / 4)) / 2;
	SH = MAPH / 10;
	COEFY = 1;
	if (all->amap->nb_x < 20)
		COEFZ = 10;
	else if (all->amap->nb_x < 40)
		COEFZ = 40;
	else
		COEFZ = ECART * 2;
	mlx_clear_window(MLX, WIN);
	draw_map(all);
	return (1);
}
