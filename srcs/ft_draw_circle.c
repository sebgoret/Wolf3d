/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:41:32 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 19:19:11 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_circle(t_env *e, int r, int x, int y)
{
	float		a;
	t_point		p;

	a = 0;
	if (r < 0)
		return ;
	while (a < 360)
	{
		p.x = x + (r * cos(a));
		p.y = y + (r * sin(a));
		ft_put_pix_in_img(e->img, &p);
		a += M_PI / (4 * r);
	}
}
