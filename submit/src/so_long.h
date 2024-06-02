/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:58:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 21:09:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mxw_types.h"

typedef struct s_sl_this
{
	t_mxw			*mxw;
	t_mxw_window	*so_long_window;
}	t_sl_this;


int	sl_keyboard_handler(int keycode, t_sl_this *vars);
int	sl_loop(t_mxw *mxw, t_sl_this *loop_args);
int	sl_setup(t_mxw *mxw, t_sl_this *setup_args);

#endif