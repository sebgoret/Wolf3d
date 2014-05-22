/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 22:17:29 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 20:09:17 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_init_env(t_env *e)
{
	t_img	*i;

	i = e->img;
	i->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->ln_size, &i->endian);
	i->color = 0x4B0082;
	i->pos_x = 1.0;
	i->pos_y = 1.0;
	i->angle = 0.0;
	ft_draw_wall(e);
	mlx_put_image_to_window(e->mlx, e->win, i->img, 0, 0);
}

int				main(void)
{
	t_env		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, TITLE);
	ft_init_env(&e);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
