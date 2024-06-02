/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_flip_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:04:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 20:49:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mxw_types.h"

int	mxw_flip_screen(t_mxw *mxw, t_mxw_window *window)
{
	int result;

	result = mlx_put_image_to_window(mxw->mlx, window->mlx_win,
		window->img_buf->img, 0, 0);
	return (result);
}
