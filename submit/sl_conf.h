/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_conf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:40:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 21:04:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_CONF_H
# define SL_CONF_H

# define PLAYER_ANIMATION_RATE 110
# define BLOCK_TILE_WIDTH 32
# define BLOCK_TILE_HEIGHT 32
# define MAX_WINDOW_TILE_WIDTH 16
# define MAX_WINDOW_TILE_HEIGHT 16
# define IMAGE_SCALE 2
# define MAX_GAME_TICK 1000000
# define WINDOW_TITLE "solong"

# ifdef BONUS
# else
#  define PRINT_MOVE_COUNTER_TO_SHELL
# endif

#endif
