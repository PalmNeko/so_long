/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:57:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:22:51 by tookuyam         ###   ########.fr       */
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
	t_mxw_image			*cut_image;

	setup_args->mxw = mxw;
	so_long_window = mxw_new_window(mxw, 1920, 1080, "Hello world!");
	if (so_long_window == NULL)
		return (-1);
	setup_args->so_long_window = so_long_window;
	cut_image = output_test_image(mxw);
	if (cut_image == NULL)
		return (mxw_destroy_window(so_long_window), -1);
	mxw_put_image_to_window(so_long_window, cut_image, 0, 0);
	mxw_destroy_image(cut_image);
	mxw_flip_screen(mxw, so_long_window);
	mxw_add_event(so_long_window, ON_DESTROY, _destroy, setup_args);
	mxw_add_event(so_long_window, ON_KEYDOWN, sl_keyboard_handler, setup_args);
	return (0);
}

t_mxw_image	*output_test_image(t_mxw *mxw)
{
	t_mxw_image			*textures;
	t_mxw_spritesheet	*sprite_sheet;
	t_mxw_image			*cut_image;
	int					width;
	int					height;

	textures = mxw_xpm_file_to_image(mxw, "textures", &width, &height);
	if (textures == NULL)
		return (NULL);
	sprite_sheet = mxw_new_spritesheet(mxw, textures, 16, 16);
	mxw_destroy_image(textures);
	if (sprite_sheet == NULL)
		return (NULL);
	cut_image = mxw_cut_spritesheet(mxw, sprite_sheet, 0, 0);
	mxw_destroy_spritesheet(sprite_sheet);
	return (cut_image);
}
