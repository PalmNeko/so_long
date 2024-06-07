/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:16:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:33:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_H
# define MXW_H

# include "mxw_types.h"

# define AUTO_CLOSE_TICK 30000

int					mxw_start(
						int (*setup)(),
						int (*loop)(),
						void *setup_args,
						void *loop_args);
void				mxw_set_end(t_mxw *mxw);

/**
 * t_mxw
 */
t_mxw				*mxw_new_mxw(void);
void				mxw_destroy_mxw(t_mxw *mxw);

/**
 * t_mxw_window
 */
t_mxw_window		*mxw_new_window(
						t_mxw *mxw, int size_x, int size_y, char *title);
void				mxw_destroy_window(t_mxw_window *win);
int					mxw_put_image_to_window(
						t_mxw_window *window,
						t_mxw_image *img_ptr,
						int x,
						int y);
int					mxw_flip_screen(t_mxw *mxw, t_mxw_window *window);
int					mxw_add_event(
						t_mxw_window *window,
						t_mxw_event mxw_event,
						int (*funct)(),
						void *param);

/**
 * t_mxw_image
 */
t_mxw_image			*mxw_new_image(t_mxw *mxw, int width, int height);
t_mxw_image			*mxw_cut_image(t_mxw_cut_image_param *param);
t_mxw_image			*mxw_xpm_file_to_image(
						t_mxw *mxw,
						char *filename,
						int *width,
						int *height);
void				mxw_destroy_image(t_mxw_image *img);
int					mxw_put_image_to_image(
						t_mxw_image *canvas,
						t_mxw_image *image,
						int x,
						int y);
void				mxw_pixel_put_to_image(
						t_mxw_image *data, int x, int y, int color);
int					mxw_pixel_get_from_image(t_mxw_image *data, int x, int y);
int					mxw_print_image(t_mxw_image *image);
t_mxw_image			*mxw_clone_image(t_mxw *mxw, t_mxw_image *image);

/**
 * t_mxw_spritesheet
*/
t_mxw_spritesheet	*mxw_new_spritesheet(
						t_mxw *mxw,
						t_mxw_image *spritesheet,
						int img_width,
						int img_height);
void				mxw_destroy_spritesheet(t_mxw_spritesheet *spritesheet);
t_mxw_image			*mxw_cut_spritesheet(
						t_mxw *mxw,
						t_mxw_spritesheet *sheet,
						int x,
						int y);

/**
 * t_mxw_flipbook
*/
t_mxw_flipbook		*mxw_new_flipbook(
						t_mxw *mxw, t_mxw_image **images, int size);
void				mxw_destroy_flipbook(t_mxw_flipbook *flipbook);
void				mxw_reset_flipbook(t_mxw_flipbook *flipbook);
int					mxw_flip_flipbbook(t_mxw_flipbook *flipbook, int cnt);
t_mxw_image			*mxw_get_image_from_flipbook(t_mxw_flipbook *flipbook);
void				mxw_reset_flipbook(t_mxw_flipbook *flipbook);
t_mxw_flipbook		*mxw_clone_flipbook(t_mxw *mxw, t_mxw_flipbook *flipbook);

/**
 * t_mxw_body
*/
t_mxw_body			*mxw_new_body(t_mxw *mxw, t_mxw_flipbook *flipbook);
void				mxw_destroy_body(t_mxw_body *body);

/**
 *  MLX Utilities.
 */
int					create_trgb(
						unsigned char t,
						unsigned char r,
						unsigned char g,
						unsigned char b);
unsigned char		get_t(int trgb);
unsigned char		get_r(int trgb);
unsigned char		get_g(int trgb);
unsigned char		get_b(int trgb);
void				*mxw_foreach_image(t_mxw_foreach_image_param *param);

#endif
