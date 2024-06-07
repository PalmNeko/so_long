/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_mouse_event_handlers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:26:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

int	mxw_int_mousedown_handler(int button, int x, int y, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[ON_MOUSEDOWN])
	{
		event = &param->event_handlers[ON_MOUSEDOWN][index];
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
	while (index < param->event_handlers_cnt[ON_MOUSEUP])
	{
		event = &param->event_handlers[ON_MOUSEUP][index];
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
	while (index < param->event_handlers_cnt[ON_MOUSEMOVE])
	{
		event = &param->event_handlers[ON_MOUSEMOVE][index];
		event->handler(x, y, event->param);
		index++;
	}
	return (0);
}
