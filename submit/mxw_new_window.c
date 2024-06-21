/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 16:35:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <X11/X.h>
#include "mxw.h"
#include "mxw_int.h"
#include "libft.h"

t_mxw_window	*_mxw_new_window(t_mxw *mxw, int width, int height);
static int		_add_window_list(t_mxw *mxw, t_mxw_window *window);
static int		add_events(t_mxw_window *window);

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
	window->width = size_x;
	window->height = size_y;
	ft_memset(window->event_handlers, 0,
		sizeof(t_mxw_event_handler) * MAX_EVENT_CNT * MXW_EVENT_HANDLER);
	ft_memset(window->event_handlers_cnt, 0, sizeof(int) * MAX_EVENT_CNT);
	add_events(window);
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

static int	add_events(t_mxw_window *window)
{
	mlx_hook(window->mlx_win, DestroyNotify, 0,
		mxw_int_destroy_handler, window);
	mlx_hook(window->mlx_win, Expose, 0,
		mxw_int_expose_handler, window);
	mlx_hook(window->mlx_win, KeyPress, KeyPressMask ,
		mxw_int_keydown_handler, window);
	mlx_hook(window->mlx_win, KeyRelease, KeyReleaseMask,
		mxw_int_keyup_handler, window);
	mlx_hook(window->mlx_win, ButtonPress, ButtonPressMask,
		mxw_int_mousedown_handler, window);
	mlx_hook(window->mlx_win, ButtonRelease, ButtonReleaseMask,
		mxw_int_mouseup_handler, window);
	mlx_hook(window->mlx_win, MotionNotify, PointerMotionMask,
		mxw_int_mousemove_handler, window);
	return (0);
}
