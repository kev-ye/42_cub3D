/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:24:14 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 16:36:07 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*sglt(void)
{
	static t_cub3d	*sglt = NULL;

	if (NULL == sglt)
	{
		sglt = ft_calloc(1, sizeof(t_cub3d));
		if (NULL == sglt)
			exit_clean(E_SYS);
	}
	return (sglt);
}

void	free_clean(void **to_free)
{
	if (NULL != to_free && NULL != *to_free)
		free(*to_free);
	*to_free = NULL;
}

int	gnl(int const *fd, char **line,	void *to_free)
{
	int	ret;

	ret = get_next_line(*fd, line);
	if (ret < 0)
	{
		if (NULL != to_free)
			free_clean((void **)&to_free);
		close(*fd);
		exit_clean(E_SYS);
	}
	return (ret);
}

void	exit_clean(char *msg)
{
	if (NULL != msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	clean();
	system("leaks cub3D");
	exit(EXIT_FAILURE);
}
