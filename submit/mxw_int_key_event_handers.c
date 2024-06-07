/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_key_event_handers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:34:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:26:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

int	mxw_int_keydown_handler(int keycode, t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[ON_KEYDOWN])
	{
		event = &param->event_handlers[ON_KEYDOWN][index];
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
	while (index < param->event_handlers_cnt[ON_KEYUP])
	{
		event = &param->event_handlers[ON_KEYUP][index];
		event->handler(keycode, event->param);
		index++;
	}
	return (0);
}
