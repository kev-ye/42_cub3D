/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configParsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:30 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 19:22:00 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_path_parsing(void)
{
	t_cub3d	*ptr;
	int		fd;
	int		i;

	ptr = SGT;
	i = 0;
	while (i < PATHMAX)
	{
		fd = open(ptr->map_info.path[i++], O_RDONLY);
		if (SYSCALL_ERROR == fd)
			exit_clean(E_PATH);
		close(fd);
	}
}

void	_get_config(char const *path)
{
	t_cub3d	*ptr;
	t_list	*tmp;
	t_io	io_stream;

	ft_bzero(&io_stream, sizeof(io_stream));
	io_stream.fd = open(path, O_RDONLY);
	if (SYSCALL_ERROR == io_stream.fd)
		exit_clean(E_SYS);
	io_stream.ret = 1;
	tmp = NULL;
	while (io_stream.ret > 0)
	{
		io_stream.ret = gnl(&(io_stream.fd), &(io_stream.line), NULL);
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(io_stream.line)));
		free_clean((void **)&(io_stream.line));
	}
	close(io_stream.fd);
	ptr = SGT;
	ptr->config = lst2tab(tmp);
	ft_lstclear(&tmp, NULL);
}

void	_config_empty(void)
{
	int	i;

	i = 0;
	while (NULL != SGT->config && NULL != SGT->config[i])
	{
		if ('\0' != SGT->config[i++])
			break ;
	}
	if (NULL == SGT->config[i])
		exit_clean(E_EMPTY);
}

void	_filename_check(char const *path)
{
	int		i;
	size_t	len;

	len = ft_strlen(path) - 1;
	i = len;
	while (-1 != i)
		if ('.' == path[i--])
			break ;
	if (i == -1 || 4 != ft_strlen(path + i)
		|| 0 != ft_strcmp(".cub", path + i))
		exit_clean(USAGE);
	
}

void	config_parsing(char const *path)
{
	int	index;

	_filename_check(path);
	_get_config(path);
	_config_empty();
	index = info_config_parsing();
	_path_parsing();
	map_config_parsing(index);
	map_parsing();
}
