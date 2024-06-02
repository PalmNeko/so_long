/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:53:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 17:49:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mxw_types.h"

t_mxw	*mxw_init(void)
{
	t_mxw	*mxw;

	mxw = (t_mxw *)malloc(sizeof(t_mxw));
	if (mxw == NULL)
		return (NULL);
	mxw->mlx = mlx_init();
	mxw->window_list = NULL;
	mxw->loop = NULL;
	mxw->loop_args = NULL;
	mxw->is_end = false;
	return (mxw);
}
