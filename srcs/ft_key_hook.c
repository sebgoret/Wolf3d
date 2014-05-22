/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 22:36:54 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 20:11:45 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3D.h"

int		ft_key_hook(int keycode, t_env *e)
{
	if (e && (keycode == ESC))
	{
		write(1, "You've quit the program.\n", 25);
		exit(0);
	}
	else
	{
		if (e && (keycode == CTRL))
			e->img->angle += M_PI;
		else if (e && (keycode == 99))
			ft_get_color(e);
		else if (e && (keycode == 114))
		{
			e->img->pos_x = 1.0;
			e->img->pos_y = 1.0;
			e->img->angle = 0.0;
			e->img->color = 0x4B0082;
		}
		ft_move(e, keycode);
		ft_draw_wall(e);
	}
	return (0);
}
