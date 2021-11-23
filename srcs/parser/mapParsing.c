/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:57:41 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 17:30:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_check
{
	int		v;
	int		h;
	BOOL	edge1;
	BOOL	edge2;
}	t_check;

static char const	g_ply[] = {
	'N',
	'S',
	'E',
	'W',
	'\0'
};

void	_condition_adapt(BOOL const cond1, BOOL const cond2)
{
	if (TRUE == cond1 && TRUE == cond2)
		return;
	exit_clean(E_SURROUND);
}

void	_horizontal_check(char const *line, int const h_pos)
{
	t_check	check;

	if ('1' == line[h_pos])
		return ;
	ft_bzero(&check, sizeof(t_check));
	check.h = h_pos;
	while (-1 != check.h)
	{
		if (line[check.h--] == '1')
		{
			check.edge1 = TRUE;
			break ;
		}
	}
	check.h = h_pos;
	while ('\0' != line[check.h])
	{
		if (line[check.h++] == '1')
		{
			check.edge2 = TRUE;
			break ;
		}
	}
	_condition_adapt(check.edge1, check.edge2);
}

void	_vertical_check(char **map, int const v_pos, int const h_pos)
{
	t_check	check;

	if ('1' == SGT->map_info.map[v_pos][h_pos])
		return ;
	ft_bzero(&check, sizeof(t_check));
	check.v = v_pos;
	while (-1 != check.v)
	{
		if (h_pos < (int)ft_strlen(map[check.v]) && map[check.v--][h_pos] == '1')
		{
			check.edge1 = TRUE;
			break ;
		}
	}
	check.v = v_pos;
	while (NULL != map[check.v])
	{
		if (h_pos < (int)ft_strlen(map[check.v]) && map[check.v++][h_pos] == '1')
		{
			check.edge2 = TRUE;
			break ;
		}
	}
	_condition_adapt(check.edge1, check.edge2);
}

void	_one_player(void)
{
	int	i;
	int	j;
	int	k;
	int	player;

	i = 0;
	player = 0;
	while (NULL != SGT->map_info.map && NULL != SGT->map_info.map[i])
	{
		j = 0;
		while ('\0' != SGT->map_info.map[i][j])
		{
			k = 0;
			while ('\0' != g_ply[k])
			{
				if (SGT->map_info.map[i][j] == g_ply[k++])
					++player;
				if (player > 1)
					exit_clean(E_PLAYER);
			}
			++j;
		}
		++i;
	}
}

void	map_parsing(void)
{
	int i;
	int j;

	_one_player();
	i = 0;
	while (NULL != SGT->map_info.map && NULL != SGT->map_info.map[i])
	{
		j = 0;
		while ('\0' != SGT->map_info.map[i][j])
		{
			_horizontal_check(SGT->map_info.map[i], j);
			_vertical_check(SGT->map_info.map, i, j);
			++j;
		}
		++i;
	}
}