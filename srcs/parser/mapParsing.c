/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:41 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 16:06:13 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char const	g_map[] = {
	'0',
	'N',
	'S',
	'E',
	'W',
	'\0'
};

void	_horizontal_check(int pos)
{
	//
}

void	_vertical_check(int pos)
{
	//
}

void	map_parsing(void)
{
	int i;
	int j;

	i = 0;
	while (NULL != SGT->map_info.map && NULL != SGT->map_info.map[i])
	{
		j = 0;
		while ('\0' != SGT->map_info.map[i][j])
		{
			_horizontal_check(++j);
			_vertical_check(i);
		}
		++i;
	}
}