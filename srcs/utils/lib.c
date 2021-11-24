/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:29:32 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 16:14:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**lst2tab(t_list *to_tab)
{
	char	**ret;
	size_t	size;
	int		i;

	size = ft_lstsize(to_tab);
	ret = ft_calloc(size + 1, sizeof(char *));
	if (NULL == ret)
		exit_clean(E_SYS);
	i = 0;
	while (NULL != to_tab)
	{
		ret[i++] = (char *)to_tab->content;
		to_tab = to_tab->next;
	}
	ret[i] = NULL;
	return (ret);
}

size_t	strslen(char **sstr)
{
	size_t	i;

	i = 0;
	while (NULL != sstr[i])
		++i;
	return (i);
}
