/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_add_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:56:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 21:04:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mxw_types.h"

int	mxw_add_event(t_mxw_window *window,
		t_mxw_event mxw_event, int (*funct)(), void *param)
{
	return (mlx_hook(window->mlx_win, mxw_event, 0, funct, param));
}
