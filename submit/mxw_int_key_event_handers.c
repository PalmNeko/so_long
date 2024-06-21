/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_key_event_handers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:34:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 18:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include <X11/X.h>

int	mxw_int_keydown_handler(int keycode, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[KeyPress])
	{
		event = &param->event_handlers[KeyPress][index];
		event->handler(keycode, event->param);
		index++;
	}
	return (0);
}

int	mxw_int_keyup_handler(int keycode, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[KeyRelease])
	{
		event = &param->event_handlers[KeyRelease][index];
		event->handler(keycode, event->param);
		index++;
	}
	return (0);
}
