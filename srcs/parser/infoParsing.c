/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infoParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:34:42 by kaye              #+#    #+#             */
/*   Updated: 2021/11/22 18:56:42 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define INFOMAX 6

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

static char const	*g_id[] = {
	"NO",
	"SO",
	"WE",
	"EA",
	"F",
	"C",
	NULL
};

static BOOL	_id_check(
	char const *line,
	t_info *info,
	int to_check,
	int info_count[INFOMAX]
)
{
	int	i;

	if (1 == info->info)
	{
		i = 0;
		if (1 == to_check)
			i = 4;
		while (NULL != g_id[i])
		{
			if (0 == ft_strncmp(line + info->i - to_check, g_id[i], to_check))
			{
				if (i < PATHMAX)
					info->id = i;
				++info_count[i];
				return (TRUE);
			}
			++i;
		}
		return (FALSE);
	}
	return (TRUE);
}

static BOOL	_save_path(char const *line, t_info info)
{
	size_t	len;
	t_cub3d	*ptr;

	ptr = sglton();
	if (2 == info.info)
	{
		len = info.end - info.start;
		ptr->map_info.path[info.id] = ft_substr(line, info.start, len);
		if (NULL == ptr->map_info.path[info.id])
			return (FALSE);
	}
	return (TRUE);
}

static BOOL	_info_line_check(char const *line, int info_count[INFOMAX])
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.id = -1;
	while ('\0' != line[info.i])
	{
		while ('\0' != line[info.i] && ' ' == line[info.i])
			++info.i;
		info.start = info.i;
		while ('\0' != line[info.i] && ' ' != line[info.i])
			++info.i;
		if ('\0' == line[info.i] && 2 == info.info)
			break ;
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

static int	_status_check(int info_count[INFOMAX], t_list *config)
{
	int	i;

	i = 0;
	if ('\0' == ((char *)config->content)[0])
		return (e_NOCOMPLETE);
	if (FALSE == _info_line_check((char *)config->content, info_count))
		exit_clean(E_ID);
	while (i < INFOMAX)
	{
		if (0 == info_count[i])
		{
			if (NULL == config->content)
				exit_clean(E_ID);
			return (e_NOCOMPLETE);
		}
		if (info_count[i++] > 1)
			exit_clean(E_ID);
	}
	return (e_COMPLETE);
}

void	info_parsing(char const *path)
{
	t_cub3d		*ptr;
	t_list		*tmp;
	t_io		io_stream;
	static int	info_count[INFOMAX] = {0};

	ft_bzero(&io_stream, sizeof(io_stream));
	io_stream.fd = open(path, O_RDONLY);
	if (SYSCALL_ERROR == io_stream.fd)
		exit_clean(E_SYS);
	io_stream.ret = 1;
	ptr = sglton();
	while (io_stream.ret > 0)
	{
		io_stream.ret = gnl(&(io_stream.fd), &(io_stream.line), NULL);
		ft_lstadd_back(&ptr->config, ft_lstnew(ft_strdup(io_stream.line)));
		free_clean((void **)&(io_stream.line));
	}
	tmp = ptr->config;
	while (NULL != ptr->config)
	{
		printf(S_GREEN"debug line:%5c"S_NONE"%s\n", ' ', ptr->config->content);
		if (e_COMPLETE == _status_check(info_count, ptr->config))
			break ;
		ptr->config = ptr->config->next;
	}
	ptr->config = tmp;
}
