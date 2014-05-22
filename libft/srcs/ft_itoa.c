/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 23:59:13 by sebgoret          #+#    #+#             */
/*   Updated: 2014/02/14 12:27:31 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*ft_return_char(int neg, int size, int n)
{
	char	*nbr;
	int		i;
	int		a;

	nbr = ft_strnew(size + neg);
	i = 0;
	a = 1;
	while (size--)
		a *= 10;
	if (neg)
		nbr[i++] = '-';
	while (a >= 1)
	{
		nbr[i++] = ((n / a) + '0');
		n %= a;
		a /= 10;
	}
	nbr[i] = '\0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	int		neg;
	int		i;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
		neg++;
	n = (n > 0) ? n : -n;
	i = 1;
	size = 0;
	while ((n / i) > 9)
	{
		i *= 10;
		size++;
	}
	return (ft_return_char(neg, size, n));
}
