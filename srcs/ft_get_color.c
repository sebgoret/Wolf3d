/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 18:16:01 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 18:26:45 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_get_color(t_env *e)
{
	if (e->img->color == 0x4B0082)
		e->img->color = 0x24445C;
	else if (e->img->color == 0x24445C)
		e->img->color = 0xA91101;
	else
		e->img->color = 0x4B0082;
}
