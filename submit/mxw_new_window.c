/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 20:07:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "libft.h"

t_mxw_window	*_mxw_new_window(t_mxw *mxw, int width, int height);
static int		_add_window_list(t_mxw *mxw, t_mxw_window *window);
static int		on_destroy(t_mxw_window *window);

t_mxw_window	*mxw_new_window(t_mxw *mxw, int size_x, int size_y, char *title)
{
	t_mxw_window	*window;
	void			*mlx_win;

	mlx_win = mlx_new_window(mxw->mlx, size_x, size_y, title);
	if (mlx_win == NULL)
		return (NULL);
	window = _mxw_new_window(mxw, size_x, size_y);
	if (window == NULL)
		return (mlx_destroy_window(mxw->mlx, mlx_win), NULL);
	window->mlx_win = mlx_win;
	window->mxw = mxw;
	window->title = title;
	window->has_mlx_win = true;
	mxw_add_event(window, ON_DESTROY, on_destroy, window);
	if (_add_window_list(mxw, window) == -1)
		return (mxw_destroy_window(window), NULL);
	return (window);
}

t_mxw_window	*_mxw_new_window(t_mxw *mxw, int width, int height)
{
	t_mxw_window	*window;

	window = (t_mxw_window *)malloc(sizeof(t_mxw_window));
	if (window == NULL)
		return (NULL);
	window->img_buf = mxw_new_image(mxw, width, height);
	if (window->img_buf == NULL)
		return (free(window), NULL);
	return (window);
}

static int	_add_window_list(t_mxw *mxw, t_mxw_window *window)
{
	t_list			*newlst;

	newlst = ft_lstnew(window);
	if (newlst == NULL)
		return (-1);
	ft_lstadd_front(&mxw->window_list, newlst);
	return (0);
}

static int	on_destroy(t_mxw_window *window)
{
	mxw_set_end(window->mxw);
	window->has_mlx_win = false;
	mxw_destroy_window(window);
	return (0);
}
