/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startGame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:44:49 by kaye              #+#    #+#             */
/*   Updated: 2021/11/25 16:53:31 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_window(void)
{
	t_cub3d	*ptr;

	ptr = sglt();
	ptr->mlx_ptr = mlx_init();
	if (NULL == ptr->mlx_ptr)
		exit_clean(E_MLX);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, W_WIDTH, W_HEIGHT, W_NAME);
	if (NULL == ptr->win_ptr)
	{
		free_clean((void **)&ptr->mlx_ptr);
		exit_clean(E_MLX);
	}
}

void	_image(void)
{
	t_cub3d	*ptr;
	t_img	*img;

	ptr = sglt();
	img = &ptr->mlx_img;
	img->img_ptr = mlx_new_image(ptr->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (NULL == img->img_ptr)
		exit_clean(E_MLX);
	ptr->mlx_img.addr = mlx_get_data_addr(
			img->img_ptr,
			&img->bpp,
			&img->size,
			&img->endian
			);
}

int	_window_destroy(void)
{
	t_cub3d	*ptr;

	ptr = sglt();
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit_clean(NULL);
	return (1);
}

int	_game_loop(void)
{
	do_raycasting();
	key_control();
	return (1);
}

void	start_game(void)
{
	_window();
	_image();
	engine_initialize();
	mlx_hook(sglt()->win_ptr, 2, 1L << 0, key_pressing, NULL);
	mlx_hook(sglt()->win_ptr, 3, 1L << 1, key_releasing, NULL);
	mlx_hook(sglt()->win_ptr, RED_CROSS, 1L << 2, _window_destroy, NULL);
	mlx_loop_hook(sglt()->mlx_ptr, _game_loop, NULL);
	mlx_loop(sglt()->mlx_ptr);
}
