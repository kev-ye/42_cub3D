/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:34:42 by kaye              #+#    #+#             */
/*   Updated: 2021/11/21 19:57:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define INFOMAX 7

enum e_status
{
	e_NOCOMPLETE = 0,
	e_COMPLETE,
	e_DUPLICATE
};

typedef struct s_info
{
	int		i;
	int		id;
	size_t	start;
	size_t	end;
	size_t	info;
}	t_info;

typedef struct s_io
{
	int		fd;
	int		ret;
	char	*line;
}	t_io;

static char const	*g_id[] = {
	"NO",
	"SO",
	"WE",
	"EA",
	"F",
	"C",
	NULL
};

BOOL	_id_check(
	char const *line,
	t_info *info,
	int to_check,
	int info_count[INFOMAX]
)
{
	int	to_add;
	int	i;

	if (1 == info->info)
	{
		to_add = 0;
		if (1 == to_check)
			to_add = 4;
		i = 0;
		while (NULL != g_id[i])
		{
			if (0 == ft_strncmp(line, g_id[i + to_add], to_check))
			{
				if (i + to_add < PATHMAX)
					info->id = i;
				++info_count[i + to_add];
				return (TRUE);
			}
			++i;
		}
		return (FALSE);
	}
	return (TRUE);
}

BOOL	_save_path(char *line, t_info info)
{
	size_t	len;
	t_cub3d	*ptr;

	ptr = sglton();
	if (2 == info.info)
	{
		len = info.end - info.start;
		ptr->map_info.path[info.id] = ft_substr(line, info.start, len);
		if (NULL == sglton()->map_info.path[info.id])
			return (FALSE);
	}
	return (TRUE);
}

BOOL	_info_line_check(char const *line, int info_count[INFOMAX])
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.id = -1;
	while ('\0' == line[info.i])
	{
		while ('\0' == line[info.i] && ' ' == line[info.i])
			++info.i;
		info.start = info.i;
		while ('\0' != line[info.i] && ' ' != line[info.i])
			++info.i;
		info.end = info.i;
		++info.info;
		if (info.info > 2 || (1 == info.info && info.end - info.start > 2))
			return (FALSE);
		if (FALSE == _id_check(line, &info, info.end - info.start, info_count))
			return (FALSE);
		if (FALSE == _save_path(line, info))
			return (FALSE);
	}
	return (TRUE);
}

int	_status_check(int info_count[INFOMAX], t_io const *io_stream)
{
	int	i;

	i = 0;
	while (i < INFOMAX)
	{
		if (0 == info_count[i])
		{
			if (0 == io_stream->ret)
			{
				free_clean((void **)&io_stream->line);
				close(io_stream->fd);
				exit_clean(E_ID);
			}
			free_clean((void **)&io_stream->line);
			return (e_NOCOMPLETE);
		}
		if (info_count[i] > 1)
		{
			free_clean((void **)&io_stream->line);
			close(io_stream->fd);
			exit_clean(E_ID);
		}
	}
	free_clean((void **)&io_stream->line);
	return (e_COMPLETE);
}

int	info_check(char const *path) // norme pb
{
	t_io		io_stream;
	static int	info_count[INFOMAX] = {0};

	io_stream.fd = open(path, O_RDONLY);
	if (SYSCALL_ERROR == io_stream.fd)
		exit_clean(E_OPEN);
	ft_bzero(&io_stream, sizeof(io_stream));
	io_stream.ret = 1;
	while (io_stream.ret > 0)
	{
		io_stream.ret = get_next_line(io_stream.fd, &io_stream.line);
		if (io_stream.ret < 0)
		{
			close(io_stream.fd);
			exit_clean(E_SYS);
		}
		if ('\0' == io_stream.line[0])
		{
			free_clean((void **)&io_stream.line);
			continue ;
		}
		if (FALSE == _info_line_check(io_stream.line, info_count))
			exit_clean(E_ID);
		if (e_COMPLETE == _status_check(info_count, &io_stream))
			break ;
	}
	return (io_stream.fd);
}
