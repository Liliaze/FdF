/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:43:05 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/21 16:35:21 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	close_win(int keycode, t_shape *shape)
{
	printf("key = %d\n", keycode);
	draw_welcome(shape);
	if (keycode == 8)
		draw_carre(shape);
	else if (keycode == 1)
		draw_arc(shape);
	else if (keycode == 51)
		draw_del(shape);
	else if (keycode == 53 || keycode == 12)
		exit(0);
	return (1);
}
