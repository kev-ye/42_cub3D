/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:57:57 by kaye              #+#    #+#             */
/*   Updated: 2021/11/25 19:22:22 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

BOOL	img_path_parsing(char *str, int const index, int const info)
{
	t_cub3d	*ptr;

	ptr = sglt();
	if (2 == info)
	{
		if (-1 != index)
			ptr->map_info.path[index] = str;
		return (TRUE);
	}
	return (FALSE);
}

// color parsing