/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:13:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 18:22:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include "sl.h"

int	sl_loop(t_mxw *mxw, t_sl_this *loop_args)
{
	(void)mxw;
	(void)loop_args;
	loop_args->game_tick += 1;
	if (loop_args->game_tick > loop_args->game_tick_reset_time)
		loop_args->game_tick = 0;
	sl_update_player(loop_args->player, loop_args->game_tick);
	sl_draw_image(loop_args);
	mxw_flip_screen(loop_args->so_long_window);
	return (0);
}
