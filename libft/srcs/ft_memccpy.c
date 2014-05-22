/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:14:50 by sebgoret          #+#    #+#             */
/*   Updated: 2014/02/14 12:29:39 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char			*d;
	const char		*s;

	d = dst;
	s = src;
	while (n--)
	{
		if (*s == c)
			return (d + 1);
		*d++ = *s++;
	}
	return (NULL);
}
