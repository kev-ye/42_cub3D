/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:34:42 by kaye              #+#    #+#             */
/*   Updated: 2021/11/19 18:25:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char const	*g_id1[] = {
	"NO",
	"SO",
	"WE",
	"EA",
	NULL
};

static char const	*g_id2[] = {
	"F",
	"C",
	NULL
};

int	id_check(char const *line)
{
	int	i;
	int	sp_index;

	i = 0;
	sp_index = 0;
	if (' ' == line[2])
		sp_index = 2;
	else if (' ' == line[1])
		sp_index = 1;
	while (NULL != g_id1[i] && 0 != sp_index)
		if (0 == ft_strncmp(line, g_id1[i++], sp_index))
			return (sp_index);
	return (-1);
}

BOOL	info_line_check(char const *line)
{
	int	i;
	int	info;

	i = 0;
	info = 0;
	while ('\0' == line[i])
	{
		if (' ' == line[i])
		{
			++i;
			continue ;
		}
		if (0 == info)
		{
			i += id_check(line + i);
			if (-1 == i)
				return (FALSE);
			++info;
			continue ;
		}
		else
			++info;
		if (info > 2)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void	info_check(char const *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (SYSCALL_ERROR == fd)
		exit_clean(OPEN);
}
