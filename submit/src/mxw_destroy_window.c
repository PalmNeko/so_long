/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:25:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 19:10:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"

int	mxw_destroy_window(t_mxw *mxw, t_mxw_window *win)
{
	int	result;

	mxw_destroy_image(mxw->mlx, win->img_buf);
	result = mlx_destroy_window(mxw->mlx, win->mlx_win);
	free(win);
	return (result);
}
