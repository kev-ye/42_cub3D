/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sglton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:08:43 by kaye              #+#    #+#             */
/*   Updated: 2021/11/19 16:11:31 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*sglton(void)
{
	static t_cub3d	*sglton = NULL;

	if (NULL == sglton)
	{
		sglton = ft_calloc(1, sizeof(t_cub3d));
		if (NULL == sglton)
			return NULL;
	}
	return sglton;
}