/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:51:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 14:34:40 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_error(char *text)
{
	ft_putstr(text);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	all->apoint = (t_point *)ft_memalloc(sizeof(t_point));
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->amap = (t_map *)ft_memalloc(sizeof(t_map));
	all->abres = (t_bres *)ft_memalloc(sizeof(t_bres));
	if (argc > 1 && argc <= 10)
	{
		if ((MLX = mlx_init()) == NULL)
			return (0);
		MAPH = 1050;
		MAPW = 1400;
		if ((WIN = mlx_new_window(MLX, MAPW, MAPH, "My beautiful FdF")) == NULL)
			return (0);
		NAME = argv;
		launch_menu(all);
		mlx_key_hook(WIN, key_press, all);
		mlx_loop(MLX);
	}
	else
		display_error("Please, specify between 1 to 9 arguments\n");
	return (0);
}
