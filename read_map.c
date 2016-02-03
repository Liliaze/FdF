/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/03 16:38:57 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_values_of_map(t_all *all) //fonction support a enlever dans rendue final
{
	int i;
	int j;

	i = 0;
	while (all->amap->map[i])
	{
		j = 0;
		printf("map[%d][%d] cree = ", i, j);
		while (all->amap->map[i][j])
		{
			printf("%s", all->amap->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	look_size_map(t_all *all)
{
	char	tmp[2];
	int		ret;
	int		fd;

	ret = 1;
	if ((fd = open(all->amap->name, O_RDONLY)) == -1)
		display_error("Please join a correct map\n");
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) == -1)
			display_error("An error in reading the map occurred\n");
		if (*tmp == '\n' && ret != 0)
			all->amap->size++;
	}
	close(fd);
}

int		open_map(t_all *all)
{
	int	i;
	int j;
	int fd;
	int ret;
	char *line;
	char **values;

	i = 0;
	j = 0;
	printf("enter in open_map\n");
	look_size_map(all);
	printf("nb of line in map = %d", all->amap->size);
	all->amap->map = (char***)malloc(sizeof(all->amap->map) * all->amap->size + 1);
	if ((fd = open(all->amap->name, O_RDONLY)) == -1)
		display_error("Please join a correct map\n");
	printf("open is okay\n");
	while (i < all->amap->size)
	{
		ret = get_next_line(fd, &line);
		values = ft_strsplit(line, ' ');
		all->amap->map[i] = values;
		i++;
	}
	all->amap->map[i] = NULL;
	print_values_of_map(all);
	return (1);
}
