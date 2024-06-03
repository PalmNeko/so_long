/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:15:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 21:08:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mxw.h"
#include <stdio.h>

int	sl_keyboard_handler(int keycode, t_sl_this *vars)
{
	if (keycode == KEY_ESC)
		mxw_set_end(vars->mxw);
	return (0);
}
