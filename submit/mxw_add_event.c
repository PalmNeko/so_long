/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_add_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:56:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 18:47:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "mxw_types.h"

/**
 * @param x_event see <X11/X.h> header.
 */
int	mxw_add_event(t_mxw_window *window,
		int x_event, int (*funct)(), void *param)
{
	int	index;

	index = window->event_handlers_cnt[x_event];
	if (index == MXW_EVENT_HANDLER)
	{
		ft_putstr_fd("overflow handler count", 2);
		exit(1);
		return (-1);
	}
	window->event_handlers[x_event][index].handler = funct;
	window->event_handlers[x_event][index].param = param;
	window->event_handlers_cnt[x_event] = index + 1;
	return (0);
}
