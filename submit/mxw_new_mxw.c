/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_mxw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:58:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:58:34 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mxw_types.h"

t_mxw	*mxw_new_mxw(void)
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
