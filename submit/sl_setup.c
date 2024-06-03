/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:57:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 21:08:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "mxw.h"
#include "so_long.h"

int destroy(t_sl_this *vars)
{
	mxw_set_end(vars->mxw);
	mxw_destroy_image(vars->mxw, vars->so_long_window->img_buf);
	return(0);
}

int	sl_setup(t_mxw *mxw, t_sl_this *setup_args)
{
	t_mxw_image		*textures;
	t_mxw_window	*so_long_window;
	int				width;
	int				height;

	setup_args->mxw = mxw;
	so_long_window = mxw_new_window(mxw, 1920, 1080, "Hello world!");
	setup_args->so_long_window = so_long_window;
	textures = mxw_xpm_file_to_image(mxw, "textures", &width, &height);
	mxw_put_image_to_window(so_long_window, textures, 0, 0);
	mxw_flip_screen(mxw, so_long_window);
	mxw_destroy_image(mxw, textures);
	mxw_add_event(so_long_window, ON_DESTROY, destroy, setup_args);
	mxw_add_event(so_long_window, ON_KEYDOWN, sl_keyboard_handler, setup_args);
	return (0);
}
