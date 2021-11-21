/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:40:01 by kaye              #+#    #+#             */
/*   Updated: 2021/11/21 17:21:37 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "class.h"
# include "defs.h"
# include "libft.h"

/** @brief utils fonction */
t_cub3d	*sglton(void);
void	free_clean(void **);
void	exit_clean(char const *);


#endif