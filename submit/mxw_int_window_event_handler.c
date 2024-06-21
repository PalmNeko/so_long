/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_window_event_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 20:54:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include <X11/X.h>

int	mxw_int_expose_handler(t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[Expose])
	{
		event = &param->event_handlers[Expose][index];
		event->handler(event->param);
		index++;
	}
	return (0);
}

int	mxw_int_destroy_handler(t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[DestroyNotify])
	{
		event = &param->event_handlers[DestroyNotify][index];
		event->handler(event->param);
		index++;
	}
	param->has_mlx_win = false;
	mxw_destroy_window(param);
	return (0);
}
