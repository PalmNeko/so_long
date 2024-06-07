/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_add_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:56:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 22:18:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "mxw_types.h"

int	mxw_add_event(t_mxw_window *window,
		t_mxw_event mxw_event, int (*funct)(), void *param)
{
	int	index;

	index = window->event_handlers_cnt[mxw_event];
	if (index == MXW_EVENT_HANDLER)
	{
		ft_putstr_fd("overflow handler count", 2);
		exit(1);
		return (-1);
	}
	window->event_handlers[mxw_event][index].handler = funct;
	window->event_handlers[mxw_event][index].param = param;
	window->event_handlers_cnt[mxw_event] = index + 1;
	return (0);
}
