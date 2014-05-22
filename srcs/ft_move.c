/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:16:34 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 20:10:50 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_vertically_move(t_env *e, char c)
{
	float	x;
	float	y;

	if (c == 'u')
	{
		x = e->img->pos_x - sin(e->img->angle) * SPEED;
		y = e->img->pos_y + cos(e->img->angle) * SPEED;
	}
	else
	{
		x = e->img->pos_x + sin(e->img->angle) * SPEED;
		y = e->img->pos_y - cos(e->img->angle) * SPEED;
	}
	if (!ft_get_map(round(x), round(y)))
	{
		e->img->pos_x = x;
		e->img->pos_y = y;
	}
}

static void		ft_rotate(t_env *e, char c)
{
	if (c == 'r')
		e->img->angle -= ANGLE_ROT * ANGLE_RAD;
	else
		e->img->angle += ANGLE_ROT * ANGLE_RAD;
}

void			ft_move(t_env *e, int keycode)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_vertically_move(e, 'u');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_vertically_move(e, 'd');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_rotate(e, 'l');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_rotate(e, 'r');
	ft_draw_wall(e);
}
