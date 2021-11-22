/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:30 by kaye              #+#    #+#             */
/*   Updated: 2021/11/22 17:38:13 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	path_parsing(void)
{
	t_cub3d	*ptr;
	int		fd;
	int		i;

	ptr = sglton();
	i = 0;
	while (i < PATHMAX)
	{
		fd = open(ptr->map_info.path[i++], O_RDONLY);
		if (SYSCALL_ERROR == fd)
			exit_clean(E_PATH);
		close(fd);
	}
}
