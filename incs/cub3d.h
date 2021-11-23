/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:40:01 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 17:14:03 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "class.h"

/** @brief tools */
t_cub3d	*sglton(void);
void	free_clean(void **);
int		gnl(int const *, char **, void *);
char	*join(char *, char *, int const*, void *);

/** @brief lib */
char	**lst2tab(t_list *);
size_t	strslen(char **);

/** @brief exit */
void	exit_clean(char *);

/** @brief parser */
void	config_parsing(char const *);
int		info_config_parsing(void);
void	map_config_parsing(int const);
void	map_parsing(void);

#endif