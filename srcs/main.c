/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:32:49 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 19:59:31 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	*ptr;

	if (2 != ac)
		exit_clean(USAGE);
	ptr = sglt();
	ft_bzero(ptr, sizeof(t_cub3d));
	config_parsing(av[1]);
	return (SUCCESSE);
}
