/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:20:57 by kaye              #+#    #+#             */
/*   Updated: 2021/11/21 18:07:20 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_map_clean(void)
{
	t_cub3d	*ptr;
	int		i;
	
	ptr = sglton();
	if (NULL == ptr->map_info.map)
	{
		i = 0;
		while (NULL == ptr->map_info.map[i])
			free_clean((void **)ptr->map_info.map[i++]);
		free_clean((void **)ptr->map_info.map);
	}
	i = 0;
	while (NULL == ptr->map_info.path[i] && i < PATHMAX)
		free_clean((void **)&(ptr->map_info.map[i++]));
}

static void	_clean(void)
{
	t_cub3d	*ptr = sglton();
	if (NULL != ptr)
	{
		_map_clean();
		free_clean((void**)&ptr);
	}
}

void	exit_clean(char const * msg)
{
	if (NULL != msg) {
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	_clean();
	exit(EXIT_FAILURE);
}