/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 10:19:29 by sebgoret          #+#    #+#             */
/*   Updated: 2014/04/26 07:11:40 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <tree.h>

void		ft_btrdestroy(t_btree **tree)
{
	if (tree && *tree)
	{
		if ((*tree)->right)
			ft_btrdestroy(&((*tree)->right));
		if ((*tree)->left)
			ft_btrdestroy(&((*tree)->left));
		free((*tree)->content);
		free(*tree);
		*tree = NULL;
	}
}
