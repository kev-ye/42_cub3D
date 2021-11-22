/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:40:01 by kaye              #+#    #+#             */
/*   Updated: 2021/11/22 18:14:59 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "class.h"

/** @brief utils fonction */
t_cub3d	*sglton(void);
void	free_clean(void **);
void	exit_clean(char *);
int		gnl(int const *, char **, void *);
char	*join(char *, char *, int const*, void *);

/** @brief parser */
void	info_parsing(char const *);
void	path_parsing(void);
void	map_parsing(int const fd);

#endif