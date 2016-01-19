/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:27:18 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/19 18:05:06 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h> // ATTENTION AVANT RENDUE !!

# define BLACK	0x00000000
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define GREY	0x007F7F7F
# define YELLOW	0x00FFFF00
# define CYAN	0x0033FFFF
# define PINK	0x00FF7F7F
# define PURPLE 0x00FF00FF
# define BROWN	0x00663300

typedef struct	s_shape
{
	int			x;
	int			y;
	int			h;
	int			w;
	int			t;
	int			color;
}				t_shape;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
}				t_win;

int		draw_carre(t_win *win, t_shape *sh);
int		draw_arc(t_win *win, t_shape *sh);
int		event(int keycode, void *param);

#endif
