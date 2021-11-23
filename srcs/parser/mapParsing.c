/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:41 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 18:56:38 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parsing(void)
{
	int	i;
	int	j;

	i = 0;
	while (NULL != SGT->map_info.map && NULL != SGT->map_info.map[i])
	{
		printf(S_PURPLE"MAP:%5c"S_NONE"%s\n", ' ', SGT->map_info.map[i]);
		j = 0;
		while ('\0' != SGT->map_info.map[i][j])
		{
			horizontal_check(SGT->map_info.map[i], j);
			vertical_check(SGT->map_info.map, i, j);
			++j;
		}
		++i;
	}
}
