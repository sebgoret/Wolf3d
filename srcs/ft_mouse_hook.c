/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:10:30 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 20:14:08 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (e && keycode == 1)
		ft_draw_square(e, x, y);
	else if (e && keycode == 3)
		ft_draw_circle(e, 42, x, y);
	ft_expose_hook(e);
	return (0);
}
