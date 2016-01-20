/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:27:18 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/20 17:17:41 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // ATTENTION AVANT RENDUE !!

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

typedef struct	s_shape
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			h;
	int			w;
	int			t;
	int			color;
}				t_shape;

typedef struct	s_map
{
	int			l;
	int			c;
	int			ax;
	int			ay;
	int			az;
	int			bx;
	int			by;
	int			bz;
}				t_map;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
}				t_win;

void	init_shape(t_win *win, t_shape *shape);
int		close_win(int keycode, t_shape *shape);
int		draw_welcome(t_shape *sh);
int		draw_del(t_shape *sh);
int		draw_carre(t_shape *sh);
int		draw_arc(t_shape *sh);
int		event(int keycode, void *param);

#endif
