/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_window_event_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:27:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

int	mxw_int_expose_handler(t_mxw_window *param)
{
	int					index;
	t_mxw_event_handler	*event;

	index = 0;
	while (index < param->event_handlers_cnt[ON_EXPOSE])
	{
		event = &param->event_handlers[ON_EXPOSE][index];
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
	while (index < param->event_handlers_cnt[ON_DESTROY])
	{
		event = &param->event_handlers[ON_DESTROY][index];
		event->handler(event->param);
		index++;
	}
	return (0);
}
