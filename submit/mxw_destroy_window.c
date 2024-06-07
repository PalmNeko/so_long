/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:25:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:52:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"

void	mxw_destroy_window(t_mxw_window *win)
{
	mxw_destroy_image(win->img_buf);
	mlx_destroy_window(win->mxw->mlx, win->mlx_win);
	free(win);
}
