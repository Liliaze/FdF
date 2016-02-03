/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:52:57 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/03 16:29:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BLACK	0x00000000
# define BROWN	0x00663300
# define GREY	0x007F7F7F
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define ORANGE 0x00FFBC00
# define YELLOW	0x00FFFF00
# define GREEN	0x0000FF00
# define CYAN	0x0033FFFF
# define BLUE	0x0011AAFF
# define PINK	0x00ED22ED
# define SALMON	0x00FF7F7F
# define PURPLE 0x00882289

# define Q		12
# define ECHAP	53
# define ENTER	36
# define DEL	51
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define W		13
# define A		0
# define S		1
# define D		2
# define LESS	78
# define MORE	69
# define SPACE	49

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h> // ATTENTION AVANT RENDUE !!
# include "../libft/includes/libft.h"

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*image;
	int				width;
	int				height;
}					t_win;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
}					t_point;

typedef struct		s_map
{
	char			***map;
	char			*name;
	int				size;
}					t_map;

typedef struct		s_all
{
	t_point			*apoint;
	t_map			*amap;
	t_win			*awin;
}					t_all;

int		key_press(int key, t_all *all);
int		bres(t_all *all);
int		open_map(t_all * all);
void	display_error(char *text);

#endif
