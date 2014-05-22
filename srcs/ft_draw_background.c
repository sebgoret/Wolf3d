/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 13:23:40 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/18 16:08:56 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw_background(t_env *e, int floor, int sky)
{
	t_point		p;
	int			c;

	c = e->img->color;
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			e->img->color = (p.y < (HEIGHT / 2)) ? sky : floor;
			ft_put_pix_in_img(e->img, &p);
			p.x++;
		}
		p.y++;
	}
	e->img->color = c;
}
