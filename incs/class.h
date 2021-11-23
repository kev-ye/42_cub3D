/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:04:11 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 14:01:58 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# include "defs.h"

enum e_path
{
	e_NO = 0,
	e_SO,
	e_WE,
	e_EA,
	e_F,
	e_C
};

typedef struct s_io
{
	int		fd;
	int		ret;
	char	*line;
}	t_io;

typedef struct s_map
{
	char	*path[PATHMAX];
	char	**map;
}	t_map;

typedef struct s_cub3d
{
	int i;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**config;
	t_map	map_info;
}	t_cub3d;

#endif