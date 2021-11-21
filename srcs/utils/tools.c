/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:24:14 by kaye              #+#    #+#             */
/*   Updated: 2021/11/21 19:40:43 by kaye             ###   ########.fr       */
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
			exit_clean(E_SYS);
	}
	return sglton;
}

void	free_clean(void **to_free)
{
	free(*to_free);
	*to_free = NULL;
}
