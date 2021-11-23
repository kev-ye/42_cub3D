/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:58:40 by kaye              #+#    #+#             */
/*   Updated: 2021/11/23 19:56:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/** @brief anscii code */
# define S_NONE "\033[0m"
# define S_BLACK "\033[1;30m"
# define S_RED "\033[1;31m"
# define S_GREEN "\033[1;32m"
# define S_YELLOW "\033[1;33m"
# define S_BLUE "\033[1;34m"
# define S_PURPLE "\033[1;35m"
# define S_CYAN "\033[1;36m"

// /** @brief exit return define */
// # define LOG printf("here: line: ["S_RED"%d"S_NONE"] file: ["S_RED"%s"S_NONE"]\n", __LINE__, __FILE__)
// # define DEBUGP(x) printf("address: ["S_RED"%p"S_NONE"] -> ", x);LOG;
// # define DEBUGS(s) printf("content: ["S_RED"%s"S_NONE"] -> ", s);LOG;

/** @brief boolean define */
# define BOOL unsigned int
# define TRUE 1
# define FALSE 0

/** @brief exit return define */
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

/** @brief return define */
# define SUCCESSE 0
# define FAILURE 1

/** @brief syscall error */
# define SYSCALL_ERROR -1

/** @brief path number */
# define PATHMAX 4

/** @brief message */
# define USAGE "usage: ./cub3d [\033[1;33m[map].cub]\033[0m]\n"
# define E_SYS "SYSCALL failed\n"
# define E_PATH "PATH file no exist\n"
# define E_EMPTY "CONFIG is empty\n"
# define E_ID "ID error\n"
# define E_MAP "MAP: basic error\n"
# define E_SURROUND "MAP: no surround\n"
# define E_PLAYER "MAP: player != 1\n"

/** @brief includes */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

#endif
