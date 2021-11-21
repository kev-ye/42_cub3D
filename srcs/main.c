/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:32:49 by kaye              #+#    #+#             */
/*   Updated: 2021/11/21 18:04:09 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_cub3d *ptr;
	if (2 != ac)
		exit_clean(USAGE);
	ptr = sglton();
	ft_bzero(ptr, sizeof(t_cub3d));
	return (SUCCESSE);
}