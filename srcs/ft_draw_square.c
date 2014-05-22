/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 22:54:11 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/18 16:06:25 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw_square(t_env *e, int x, int y)
{
	t_point		p;
	int			size;

	size = 42;
	x = x + (size / 2);
	y = y + (size / 2);
	p.y = y - size;
	if (x <= WIDTH && y <= HEIGHT)
	{
		while (p.y < y)
		{
			p.x = x - size;
			while (p.x < x)
			{
				ft_put_pix_in_img(e->img, &p);
				p.x++;
			}
			p.y++;
		}
	}
}
