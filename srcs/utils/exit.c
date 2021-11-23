/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:20:57 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 15:47:17 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_map_clean(void)
{
	t_cub3d	*ptr;
	int		i;
	
	ptr = SGT;
	if (NULL != ptr->map_info.map)
	{
		free(ptr->map_info.map);
		ptr->map_info.map = NULL;
	}
	i = 0;
	while (i < PATHMAX)
	{
		if (NULL != ptr->map_info.path[i])
			free_clean((void **)&(ptr->map_info.path[i]));
		++i;
	}
}

static void	_clean(void)
{
	t_cub3d	*ptr;
	int		i = 0;

	ptr = SGT;
	if (NULL != ptr)
	{
		while (NULL != ptr->config[i])
			free_clean((void **)&ptr->config[i++]);
		free_clean((void **)ptr->config);
		_map_clean();
		free_clean((void **)&ptr);
	}
}

void	exit_clean(char * msg)
{
	if (NULL != msg) {
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	_clean();
	exit(EXIT_FAILURE);
}