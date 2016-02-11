/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 15:33:50 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_my_map(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			ft_memdel((void **)&MAP[i][j]);
			j++;
		}
		ft_memdel((void **)&MAP[i]);
		i++;
	}
	free(MAP);
	MAP = NULL;
}

void			zmin_and_zmax(t_all *all)
{
	int i;
	int j;

	i = 0;
	ZMAX = 0;
	ZMIN = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			if (ft_atoi(MAP[i][j]) * COEFZ > ZMAX)
				ZMAX = ft_atoi(MAP[i][j]) * COEFZ;
			if (ft_atoi(MAP[i][j]) * COEFZ < ZMIN)
				ZMIN = ft_atoi(MAP[i][j]) * COEFZ;
			j++;
		}
		i++;
	}
}

static int		look_size_map(t_all *all)
{
	char	tmp[2];
	int		ret;
	int		fd;
	int		check_data;

	ret = 1;
	check_data = 0;
	all->amap->nb_y = 0;
	fd = open(TNAME, O_RDONLY);
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) > 0)
			check_data = 1;
		if (*tmp == '\n' && ret != 0)
			all->amap->nb_y++;
	}
	close(fd);
	if (check_data == 1 && fd >= 0)
		return (1);
	all->in_menu = -1;
	mlx_clear_window(MLX, WIN);
	mlx_string_put(MLX, WIN, (MAPW - 61 * 11) / 2, MAPH / 2, RED,
			"This map is empty or invalid. Press ENTER to return in Menu.");
	return (0);
}

static void		nb_x(t_all *all, char *line)
{
	int	i;

	i = 0;
	all->amap->nb_x = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] != ' ' && line[i])
			all->amap->nb_x++;
		while (line[i] != ' ' && line[i])
			i++;
	}
}

int				open_map(t_all *all)
{
	int		i;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	if (MAP)
		free_my_map(all);
	if (!look_size_map(all))
		return (0);
	MAP = (char***)malloc(sizeof(MAP) * all->amap->nb_y + 1);
	if ((fd = open(TNAME, O_RDONLY)) == -1)
		display_error("Please join a correct map\n");
	while (++i < all->amap->nb_y)
	{
		if ((get_next_line(fd, &line)) == -1)
			display_error("Problem during the reading of the card\n");
		if (i == 0)
			nb_x(all, line);
		values = ft_strsplit(line, ' ');
		MAP[i] = values;
		free(line);
	}
	MAP[i] = NULL;
	return (1);
}
