/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:40:01 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 19:26:46 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "class.h"

/* 
 * tools
*/
t_cub3d	*sglt(void);

/*
 * utils
*/
char	**lst2tab(t_list *to_tab);
size_t	strslen(char **sstr);
int		gnl(int const *fd, char **line,	void *to_free);
void	free_clean(void **to_free);

/*
 * exit / clean
*/
void	mlx_clean(void);
void	clean(void);
void	exit_clean(char *msg);

/* 
 * parser
*/
void	config_parsing(char const *path);
int		info_config_parsing(void);
void	map_config_parsing(int constindex);
void	horizontal_check(char const *line, int consth_pos);
void	vertical_check(char **map, int const v_pos, int const h_pos);
void	map_parsing(void);

/*
 * engine
*/
/** @brief engine: player initialize */
void	player_initialize(void);

/** @brief engine: engine initialize */
void	engine_initialize(void);

/** @brief engine: game initialize */
void	start_game(void);

/** @brief engine: ray-casting utils */
void	wall_hit(t_raycast *ray);
void	projection_dist_calculate(void);
void	height_line_calculate(void);
void	pixel_to_fill_stripe_calculate(void);

/** @brief engine: do ray-casting */
void	do_raycasting(void);

#endif