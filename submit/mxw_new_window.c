/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:57:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "libft.h"

t_mxw_window	*mxw_new_window(t_mxw *mxw, int size_x, int size_y, char *title)
{
	t_mxw_window	*window;
	t_free_args		frees[5];

	window = (t_mxw_window *)malloc(sizeof(t_mxw_window));
	if (window == NULL)
		return (NULL);
	frees[0] = (t_free_args){.free_func = free, .arg = window};
	window->mxw = mxw;
	window->img_buf = mxw_new_image(mxw, size_x, size_y);
	if (window->img_buf == NULL)
		return (ft_free_iter(frees, 1), NULL);
	frees[1] = (t_free_args){.free_func = mxw_destroy_image,
		.arg = window->img_buf};
	window->mlx_win = mlx_new_window(mxw->mlx, size_x, size_y, title);
	if (window->mlx_win == NULL)
		return (ft_free_iter(frees, 2), NULL);
	window->title = title;
	return (window);
}
