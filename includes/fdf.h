/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:27:18 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/18 18:09:10 by dboudy           ###   ########.fr       */
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
# define BROWN	0x00663300

typedef struct	s_form
{
	int			x;
	int			y;
	int			h;
	int			w;
	int			t;
	int			color;
}				t_form;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
}				t_win;

int		draw_carre(t_win *win, t_form *form);
int		draw_arc_en_ciel(t_win *win, int x, int y);
int		event(int keycode, void *param);

#endif
