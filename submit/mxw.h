/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:16:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/03 11:29:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_H
# define MXW_H

# include "mxw_types.h"

int				mxw_start(
					int (*setup)(),
					int (*loop)(),
					void *setup_args,
					void *loop_args);
void			mxw_set_end(t_mxw *mxw);

/**
 * t_mxw
 */
t_mxw			*mxw_init(void);
void			mxw_destroy_mxw(t_mxw *mxw);

/**
 * t_mxw_window
 */
t_mxw_window	*mxw_new_window(
					t_mxw *mxw, int size_x, int size_y, char *title);
int				mxw_destroy_window(t_mxw *mxw, t_mxw_window *win);
int				mxw_put_image_to_window(
					t_mxw_window *window,
					t_mxw_image *img_ptr,
					int x,
					int y);
int				mxw_flip_screen(t_mxw *mxw, t_mxw_window *window);
int				mxw_add_event(
					t_mxw_window *window,
					t_mxw_event mxw_event,
					int (*funct)(),
					void *param);

/**
 * t_mxw_image
 */
t_mxw_image		*mxw_new_image(t_mxw *mxw, int width, int height);
t_mxw_image		*mxw_xpm_file_to_image(
					t_mxw *mxw,
					char *filename,
					int *width,
					int *height);
int				mxw_destroy_image(t_mxw *mxw, t_mxw_image *img);
int				mxw_put_image_to_image(
					t_mxw_image *canvas,
					t_mxw_image *image,
					int x,
					int y);
void			mxw_pixel_put_to_image(
					t_mxw_image *data, int x, int y, int color);
int				mxw_pixel_get_from_image(t_mxw_image *data, int x, int y);
int				mxw_print_image(t_mxw_image *image);

/**
 *  MLX Utilities.
 */
int				create_trgb(
					unsigned char t,
					unsigned char r,
					unsigned char g, 
					unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif
