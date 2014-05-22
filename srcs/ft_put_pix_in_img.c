/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pix_in_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 22:44:50 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 18:25:46 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_put_pix_in_img(t_img *i, t_point *p)
{
	int		pix;

	pix = (p->y * i->ln_size) + (p->x * (i->bpp / 8));
	if (((p->y >= 0) && (p->y <= HEIGHT)) && ((p->x >= 0) && (p->x <= WIDTH)))
		ft_memcpy(&(i->addr)[pix], &i->color, (i->bpp / 8));
}
