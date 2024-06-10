/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:13:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 18:09:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include "sl.h"

int	sl_loop(t_mxw *mxw, t_sl_this *loop_args)
{
	(void)mxw;
	(void)loop_args;
	sl_update_player(loop_args->player);
	sl_draw_image(loop_args);
	mxw_flip_screen(loop_args->so_long_window);
	return (0);
}
