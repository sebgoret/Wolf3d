/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:07:06 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 18:27:41 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static float	ft_ray_casting(t_env *e, int i)
{
	float		size;
	float		x;
	float		y;
	float		teta;

	x = e->img->pos_x;
	y = e->img->pos_y;
	teta = ANGLE_RAD * ((FOV / WIDTH) * i);
	while (!ft_get_map(round(x), round(y)))
	{
		y += (RAY_CASTING * cos(teta + TETA + e->img->angle));
		x -= (RAY_CASTING * sin(teta + TETA + e->img->angle));
	}
	size = sqrt(pow((x - e->img->pos_x), 2) + pow((y - e->img->pos_y), 2));
	size *= cos(TETA + teta);
	return (size);
}

static void		ft_draw_column(t_env *e, int x, float size)
{
	t_point		p;
	int			wall_size;
	int			i;

	i = 0;
	wall_size = HEIGHT / (size * 2);
	p.x = x;
	while (i < (wall_size / 2))
	{
		p.y = (HEIGHT / 2) + i;
		ft_put_pix_in_img(e->img, &p);
		p.y = (HEIGHT / 2) - i;
		ft_put_pix_in_img(e->img, &p);
		i++;
	}
}

void			ft_draw_wall(t_env *e)
{
	int		i;
	float	size;

	ft_draw_background(e, 0x98FB98, 0x87CEEB);
	i = 0;
	while (i <= WIDTH)
	{
		size = ft_ray_casting(e, i);
		ft_draw_column(e, (WIDTH - i), size);
		i++;
	}
	ft_expose_hook(e);
}
