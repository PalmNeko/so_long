/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:59:02 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:01:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_INT_H
# define MXW_INT_H

# include "mxw_types.h"

t_mxw_image	*mxw_generate_from_mlx_image(
				t_mxw *mxw, void *mlx_img, int width, int height);
void		mxw_destroy_mxw(t_mxw *mxw);
int			mxw_int_destroy_handler(t_mxw_window *param);
int			mxw_int_expose_handler(t_mxw_window *param);
int			mxw_int_keydown_handler(int keycode, t_mxw_window *param);
int			mxw_int_keyup_handler(int keycode, t_mxw_window *param);
int			mxw_int_mousemove_handler(int x, int y, t_mxw_window *param);
int			mxw_int_mouseup_handler(
				int button, int x, int y, t_mxw_window *param);
int			mxw_int_mousedown_handler(
				int button, int x, int y, t_mxw_window *param);

#endif
