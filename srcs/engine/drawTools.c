/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawTools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:18:11 by kaye              #+#    #+#             */
/*   Updated: 2021/11/25 16:46:12 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_color_vertically(t_line *l, unsigned int const color)
{
	t_cub3d	*ptr;
	t_img	*img;

	ptr = sglt();
	img = &ptr->mlx_img;
	l->line_y = l->start;
	if (l->line_y >= 0)
	{
		while (l->line_y < l->end)
		{
			ft_memcpy(
				img->addr + l->line_y * img->size + l->line_x * (img->bpp / 8),
				&color,
				sizeof(unsigned int)
				);
			++l->line_y;
		}
	}
}

void	fill_text_vertically(t_line *l, t_img tex, t_raycast *ray)
{
	t_img	img;
	double	step;
	double	tex_pos;

	img = sglt()->mlx_img;
	l->line_y = l->start;
	step = (double)tex.height / (double)ray->line_height;
	tex_pos = (l->line_y - W_HEIGHT / 2 + ray->line_height / 2) * step;
	if (l->line_y >= 0)
	{
		while (l->line_y < l->end)
		{
			l->tex_y = (int)tex_pos;
			tex_pos += step;
			ft_memcpy(
				img.addr + (l->line_y * img.size) + (l->line_x * (img.bpp / 8)),
				tex.addr + (l->tex_y * tex.size) + (l->tex_x * (tex.bpp / 8)),
				sizeof(unsigned int)
				);
			++l->line_y;
		}
	}
}
