/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:24:14 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 15:45:54 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*sglton(void)
{
	static t_cub3d	*sglton = NULL;

	if (NULL == sglton)
	{
		sglton = ft_calloc(1, sizeof(t_cub3d));
		if (NULL == sglton)
			exit_clean(E_SYS);
	}
	return sglton;
}

void	free_clean(void **to_free)
{
	if (NULL != to_free && NULL != *to_free)
		free(*to_free);
	*to_free = NULL;
}

int		gnl(int const *fd, char **line,	void *to_free)
{
	int ret;

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

char	*join(char *s1, char *s2, int const *fd, void *to_free)
{
	char *ret;

	ret = ft_strjoin_gnl(s1, s2);
	if (NULL == ret)
	{
		if (NULL != fd)
			close(*fd);
		if (NULL != to_free)
			free_clean((void **)&to_free);
		exit_clean(E_SYS);
	}
	return (ret);
}