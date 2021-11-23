/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapConfigParsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:28 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 15:57:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char const	g_map[] = {
	'0',
	'1',
	'N',
	'S',
	'E',
	'W',
	' ',
	'\0'
};

void	_get_map(int const index)
{
	t_cub3d	*ptr;
	t_list	*tmp;
	int		i;

	i = index;
	while (NULL != SGT->config[i] && '\0' == SGT->config[i][0])
		++i;
	tmp = NULL;
	while (NULL != SGT->config[i])
	{
		if (NULL == SGT->config[i + 1] && SGT->config[i][0] == '\0')
			break ;
		ft_lstadd_back(&tmp, ft_lstnew((char *)SGT->config[i++]));
	}
	ptr = SGT;
	ptr->map_info.map = lst2tab(tmp);
	ft_lstclear(&tmp, NULL);
}

void	_map_line_check(char *line)
{
	int	i;
	int	j;

	if ('\0' == line[0])
		exit_clean(E_MAP);
	i = 0;
	while ('\0' != line[i])
	{
		j = 0;
		while ('\0' != g_map[j])
		{
			if (line[i] == g_map[j++])
				break ;
		}
		if ('\0' == g_map[j])
			exit_clean(E_MAP);
		++i;
	}
}

void	map_config_parsing(int const index)
{
	int	i;

	_get_map(index);
	i = 0;
	while (NULL != SGT->map_info.map && NULL != SGT->map_info.map[i])
	{
		printf(S_PURPLE"MAP:%5c"S_NONE"%s\n", ' ', SGT->map_info.map[i]);
		_map_line_check(SGT->map_info.map[i++]);
	}
}
