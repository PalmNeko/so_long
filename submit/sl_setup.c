/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:57:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 17:35:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "mxw.h"
#include "so_long.h"

int	_destroy(t_sl_this *vars)
{
	mxw_set_end(vars->mxw);
	return (0);
}

t_mxw_image	*output_test_image(t_mxw *mxw);

int	sl_setup(t_mxw *mxw, t_sl_this *setup_args)
{
	t_mxw_window		*so_long_window;

	setup_args->mxw = mxw;
	if (sl_load(setup_args) != 0)
		return (-1);
	so_long_window = mxw_new_window(mxw, 1920, 1080, "Hello world!");
	if (so_long_window == NULL)
		return (sl_unload(setup_args), -1);
	setup_args->so_long_window = so_long_window;
	mxw_put_image_to_window(so_long_window,
		mxw_get_image_from_flipbook(*setup_args->player->now_flipbook), 0, 0);
	mxw_flip_screen(mxw, so_long_window);
	mxw_add_event(so_long_window, ON_DESTROY, _destroy, setup_args);
	mxw_add_event(so_long_window, ON_KEYDOWN, sl_keyboard_handler, setup_args);
	return (0);
}
