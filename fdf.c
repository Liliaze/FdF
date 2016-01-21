/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:42:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/21 16:44:04 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int	getnbr(char *str, int *point)
{
	int len;

	len = 0;
	while (str != ' ')
	{
		len++;
	}
	point = atoii

	return (len);
}
*/
int	draw_map(t_map *map)
{
	int	i;
	int	line;
	int	ecart;
	int	ecartl;

	line = 0;
	ecartl = 10;
	while (map->map[line] < map->map[map->l])
	{
		i = 0;
		ecart = 10;
		while (map->map[line][i])
		{
			mlx_pixel_put(map->mlx, map->win, i + ecart, line + ecartl, BLUE);
			printf("i + ecart = %d, line + ecartl = %d\n", i + ecart, line + ecartl);
			i++;
			ecart = 10 * i;
		}
		line++;
		ecartl = 10 * line;
	}
	return (1);
}

int	read_map(t_map *map, char *av)
{
	int		fd;
	int		ret;
	int		i;

	ret = 1;
	fd = open(av, O_RDONLY);
	printf("\n\n======= MAP ======\nfd = %d\n", fd);
	map->map = (char **)malloc(sizeof(char*) * (map->l + 1));
	printf("map->l = %d", map->l);
	i = 0;
	while (i < map->l)
	{
		ret = get_next_line(fd, &(map->map[i]));
		printf("i = %d, ret = %d et map[i] = %s\n", i, ret, map->map[i]);
		i++;
	}
	map->map[i] = ft_strnew(1);
	printf("i = %d, ret = %d et map[i] = %s\n", i, ret, map->map[i]);
	close(fd);
	return (1);
}


int	map_line(t_map *map, char *av)
{
	int		fd;
	int		ret;
	char	*tmp;

	fd = open(av, O_RDONLY);
	ret = 1;
	map->l = 0;
	printf("\n\n----MAP_LINE-----\nfd = %d\n", fd);
	tmp = ft_strnew(1);;
	ft_putstr("1");
	while (ret)
	{
		ret = read(fd, tmp, 1);
		if (*tmp == '\n' && ret == 1)
			map->l++;
		printf("l = %d et ret = %d et tmp = %c\n", map->l, ret, *tmp);
	}
	close(fd);
	return (1);
}


int	main(int ac, char **av)
{
	t_map	map;
	t_win	win;
	t_shape	shape;

	if (ac > 1)
	{
		win.mlx = mlx_init();
		win.h = 300;
		win.w = 300;
		win.win = mlx_new_window(win.mlx, win.h, win.w, "Test recup new_image");
		init_shape(&win, &shape, &map);
		map_line(&map, av[1]);
		read_map(&map, av[1]);
		draw_map(&map);
		//mlx_key_hook(win.win, close_win, &shape);
		mlx_loop(win.mlx);
	}
	return (0);
}
