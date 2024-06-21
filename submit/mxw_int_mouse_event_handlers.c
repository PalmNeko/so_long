/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_mouse_event_handlers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 18:46:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include <X11/X.h>

int	mxw_int_mousedown_handler(int button, int x, int y, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[ButtonPress])
	{
		event = &param->event_handlers[ButtonPress][index];
		event->handler(button, x, y, event->param);
		index++;
	}
	return (0);
}

int	mxw_int_mouseup_handler(int button, int x, int y, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[ButtonRelease])
	{
		event = &param->event_handlers[ButtonRelease][index];
		event->handler(button, x, y, event->param);
		index++;
	}
	return (0);
}

int	mxw_int_mousemove_handler(int x, int y, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[MotionNotify])
	{
		event = &param->event_handlers[MotionNotify][index];
		event->handler(x, y, event->param);
		index++;
	}
	return (0);
}
