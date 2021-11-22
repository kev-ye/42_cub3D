/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:28 by kaye              #+#    #+#             */
/*   Updated: 2021/11/22 17:57:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_get_map(int const fd)
{
	t_io	io_stream;
	t_cub3d	*ptr;
	char	*map;

	ft_bzero(&io_stream, sizeof(t_io));
	ptr = sglton();
	io_stream.ret = 1;
	map = NULL;
	while (io_stream.ret > 0)
	{
		io_stream.ret = gnl(&fd, &(io_stream.line), (void *)map);
		if ('\0' == io_stream.line[0])
		{
			free_clean((void **)&map);
			free_clean((void **)&(io_stream.line));
			close(fd);
			exit_clean(E_MAP);
		}
		map = join(map, ft_strdup(io_stream.line), &fd, (void *)io_stream.line);
		map = join(map, ft_strdup("\n"), &fd, (void *)io_stream.line);
		free_clean((void **)&(io_stream.line));
	}
	ptr->map_info.map = ft_split(map, '\n');
	free_clean((void **)&map);
}

void	map_parsing(int const fd)
{
	t_io	io_stream;

	ft_bzero(&io_stream, sizeof(t_io));
	io_stream.ret = 1;
	while (io_stream.ret > 0)
	{
		io_stream.ret = gnl(&fd, &(io_stream.line), NULL);
		if ('\0' == io_stream.line[0])
		{
			free_clean((void **)&(io_stream.line));
			continue ;
		}
		else
			break ;
	}
	_get_map(fd);
	int i = 0;
	while (sglton()->map_info.map[i] != NULL)
		printf("%s\n",sglton()->map_info.map[i++]);
	close(fd);
}
