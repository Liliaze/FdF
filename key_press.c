/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:36:39 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 14:52:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	zoom_key(t_all *all, int key)
{
	if (key == LESS)
	{
		ECART = ECART * 0.90;
		COEFZ = COEFZ * 0.90;
		mlx_clear_window(MLX, WIN);
		draw_map(all);
	}
	else
	{
		ECART = ECART * 1.1;
		COEFZ = COEFZ * 1.1;
		mlx_clear_window(MLX, WIN);
		draw_map(all);
	}
	return (1);
}

static int	move_map(t_all *all, int key)
{
	if (key == W)
		SH = SH + 20;
	else if (key == S)
		SH = SH - 20;
	else if (key == A)
		SW = SW + 30;
	else
		SW = SW - 30;
	mlx_clear_window(MLX, WIN);
	draw_map(all);
	return (1);
}

static int	increase_z(t_all *all, int key)
{
	if (key == UP)
		COEFZ = COEFZ + 10;
	else
		COEFZ = COEFZ - 10;
	mlx_clear_window(MLX, WIN);
	draw_map(all);
	return (1);
}

static int	rotate_map(t_all *all, int key)
{
	if (key == Q || key == LEFT)
		COEFY = COEFY * 1.05;
	else
		COEFY = COEFY * 0.95;
	mlx_clear_window(MLX, WIN);
	draw_map(all);
	return (1);
}

int			key_press(int key, t_all *all)
{
	if (key == ECHAP)
		exit(1);
	if (key == DEL)
		mlx_clear_window(MLX, WIN);
	if (key == ENTER)
		launch_menu(all);
	if (all->in_menu == 1 && ((key >= ONE && key <= NINE && key != 24 &&
			key != 27) || (key >= ONE2 && key <= NINE2 && key != 90)))
		launch_new_map(all, key);
	if (all->in_menu == 0 && (key == W || key == S || key == A || key == D))
		move_map(all, key);
	if (all->in_menu == 0 && (key == LESS || key == MORE))
		zoom_key(all, key);
	if (all->in_menu == 0 && (key == UP || key == DOWN))
		increase_z(all, key);
	if (all->in_menu == 0 &&
			(key == Q || key == E || key == LEFT || key == RIGHT))
		rotate_map(all, key);
	return (0);
}
