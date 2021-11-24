/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:42:19 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 18:06:28 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_raycastring_initialize(void)
{
	t_player	ply;
	t_raycast	*ray;

	ply = sglt()->player;
	ray = &sglt()->raycast;
	ray->camera_x = 2 * ray->pix / (double)W_WIDTH - 1;
	ray->ray_dir_x = ply.dir_x + (ply.plane_x * ray->camera_x);
	ray->ray_dir_y = ply.dir_y + (ply.plane_y * ray->camera_x);
	ray->map_x = (int)ply.pos_x;
	ray->map_y = (int)ply.pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	_side_dist_initialize(void)
{
	t_player	ply;
	t_raycast	*ray;

	ply = sglt()->player;
	ray = &sglt()->raycast;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ply.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ply.pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ply.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ply.pos_y) * ray->delta_dist_y;
	}
}
