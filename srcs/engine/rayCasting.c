/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:42:19 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 18:54:43 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_raycasting_initialize(void)
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

void	_raycasting(void)
{
	t_raycast	*ray;

	ray = &sglt()->raycast;
	_raycasting_initialize();
	_side_dist_initialize();
	wall_hit(ray);
	projection_dist_calculate();
	height_line_calculate();
	pixel_to_fill_stripe_calculate();
	ray->zbuffer[ray->pix] = ray->perp_wall_dist;
}

void	do_raycasting(void)
{
	t_cub3d		*ptr;
	t_raycast	*ray;

	ptr = sglt();
	ray = &ptr->raycast;
	ray->zbuffer = ft_calloc(W_WIDTH, sizeof(double));
	if (NULL == ray->zbuffer)
		exit_clean(E_SYS);
	while (ray->pix < W_WIDTH)
	{
		_raycasting();
		++ray->pix;
	}
	mlx_put_image_to_window(
		ptr->mlx_ptr, ptr->win_ptr, ptr->mlx_img.img_ptr, 0, 0);
	free_clean((void **)ray->zbuffer);
}