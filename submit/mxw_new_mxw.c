/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_mxw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:58:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 23:32:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mxw_types.h"

/**
 * @param lf int loop_function(t_mxw *, void *loop_args) is called every loop.
 * @param larg loop_args which pass loop_function.
 * @param df int destroy_function(void *destroy_args) is called on destroy mxw.
 * @param darg destroy_args which pass destroy_function.
 * @return t_mxw instance in memory. ref. mxw_destroy_mxw().
 */
t_mxw	*mxw_new_mxw(int (*lf)(), void *larg, int (*df)(), void *darg)
{
	t_mxw	*mxw;

	mxw = (t_mxw *)malloc(sizeof(t_mxw));
	if (mxw == NULL)
		return (NULL);
	mxw->mlx = mlx_init();
	if (mxw->mlx == NULL)
		return (free(mxw), NULL);
	mxw->window_list = NULL;
	mxw->loop = lf;
	mxw->loop_args = larg;
	mxw->destroy = df;
	mxw->destroy_args = darg;
	mxw->is_exit = false;
	mxw->is_end = false;
	return (mxw);
}
