/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:40:01 by kaye              #+#    #+#             */
/*   Updated: 2021/11/24 15:31:36 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "class.h"

/** @brief tools */
t_cub3d	*sglt(void);
void	free_clean(void **to_free);
int		gnl(int const *fd, char **line,	void *to_free);

/** @brief lib */
char	**lst2tab(t_list *to_tab);
size_t	strslen(char **sstr);

/** @brief exit / clean */
void	mlx_clean(void);
void	clean(void);
void	exit_clean(char *msg);

/** @brief parser */
void	config_parsing(char const *path);
int		info_config_parsing(void);
void	map_config_parsing(int constindex);
void	horizontal_check(char const *line, int consth_pos);
void	vertical_check(char **map, int const v_pos, int const h_pos);
void	map_parsing(void);

/** @brief mlx */
void	game_initialize(void);

#endif