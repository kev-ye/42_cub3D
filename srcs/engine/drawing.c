/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:15:23 by kaye              #+#    #+#             */
/*   Updated: 2021/11/25 14:38:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_draw_side(t_line *l, double wall_x, t_raycast *ray)
{
	int			tex_x;
	t_img		tex;

	tex = sglt()->tex_img[0];
	tex_x = (int)(wall_x * (double)tex.width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		tex_x = tex.width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		tex_x = tex.width - tex_x - 1;
	l->start = ray->draw_start;
	l->end = ray->draw_end;
	l->tex_x = tex_x;
	fill_text_vertically(l, tex, ray);
}

void	_draw_ceiling_floor(t_line *l, t_raycast *ray)
{
	l->start = 0;
	l->end = ray->draw_start;
	fill_color_vertically(l, 0x00FF00);
	l->start = ray->draw_end;
	l->end = W_HEIGHT;
	fill_color_vertically(l, 0xFFFF00);
}

void	drawing(t_raycast *ray)
{
	t_player	ply;
	t_line		l;
	double		wall_x;

	ply = sglt()->player;
	ft_bzero(&l, sizeof(t_line));
	l.line_x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = ply.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ply.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	// if (sglt()->map_info.map[ray.map_y][ray.map_x] == '1')
	// 	_draw_side(&l, wall_x);
	_draw_ceiling_floor(&l, ray);
}