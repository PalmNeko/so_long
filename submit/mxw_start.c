/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:19:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 23:48:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include "mxw.h"
#include "mxw_int.h"

int	mxw_loop(t_mxw *mxw);

/**
 *
 * @brief run setup -> run loop
 * @return 1 if occur error in internal init.
 * 	value which is setup return value if 1 if occur error in setup.
 * @note destroy function will call when occur error or assign
 *  true to mxw->is_exit.
 */
int	mxw_start(t_mxw_start_param param)
{
	t_mxw	*mxw;
	int		err_no;

	mxw = mxw_new_mxw();
	if (mxw == NULL)
		return (param.destroy(param.destroy_args), 1);
	err_no = ((int (*)(t_mxw *, void *))param.setup)(mxw, param.setup_args);
	if (err_no != 0)
		mxw_set_end(mxw);
	mxw->loop = (int (*)(t_mxw *, void *))param.loop;
	mxw->loop_args = param.loop_args;
	mxw->destroy = (int (*)(void *))param.destroy;
	mxw->destroy_args = param.destroy_args;
	mlx_loop_hook(mxw->mlx, mxw_loop, mxw);
	mlx_loop(mxw->mlx);
	return (0);
}

int	mxw_loop(t_mxw *mxw)
{
	mxw->loop(mxw, mxw->loop_args);
	if (mxw->is_exit == true)
	{
		mxw_destroy_mxw(mxw);
		exit(0);
	}
	if (mxw->is_end == true)
	{
		mxw->destroy(mxw->destroy_args);
		mxw_int_clean_windows(mxw);
		mxw->is_exit = true;
	}
	if (mxw->window_list == NULL)
	{
		mxw->idle_cnt += 1;
		if (mxw->idle_cnt > AUTO_CLOSE_TICK)
			mxw->is_end = true;
	}
	else
		mxw->idle_cnt = 0;
	return (0);
}
