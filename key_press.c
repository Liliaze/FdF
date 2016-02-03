/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:36:39 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/01 18:35:19 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_all *all)
{
	printf("key = %d\n", key);
	all->awin->width = 640;
	if (key == Q || key == ECHAP)
		exit(1);
	if (key == DEL)
		mlx_clear_window(all->awin->mlx, all->awin->win);
	/*if (key == ENTER)
		launch_map_or_menu();
	if (key == UP || key == W)
		move_up();
	if (key == DOWN || key == S)
		move_down();
	if (key == LEFT || key == A)
		move_left();
	if (key == RIGHT || key == D)
		move_right();
	if (key == SPACE)
		change_color();
	if (key == LESS)
		zoom_less();
	if (key == MORE)
		zoom_more();*/
	return (0);
}
