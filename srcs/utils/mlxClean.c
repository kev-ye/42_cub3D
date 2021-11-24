/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxClean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:54 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 16:35:11 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_img_clean(t_cub3d	*ptr)
{
	if (NULL != ptr->mlx_img.img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->mlx_img.img_ptr);
}

void	mlx_clean(void)
{
	t_cub3d	*ptr;

	ptr = sglt();
	_img_clean(ptr);
}