/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:38:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"

t_mxw_window	*mxw_new_window(t_mxw *mxw, int size_x, int size_y, char *title)
{
	t_mxw_window	*window;

	window = (t_mxw_window *)malloc(sizeof(t_mxw_window));
	if (window == NULL)
		return (NULL);
	window->mxw = mxw;
	window->img_buf = mxw_new_image(mxw, size_x, size_y);
	if (window->img_buf == NULL)
		return (free(window), NULL);
	window->mlx_win = mlx_new_window(mxw->mlx, size_x, size_y, title);
	if (window->mlx_win == NULL)
		return (free(window), mxw_destroy_image(window->img_buf), NULL);
	window->title = title;
	return (window);
}
