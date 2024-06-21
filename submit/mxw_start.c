/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:19:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 23:33:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include "mxw.h"
#include "mxw_int.h"

int		mxw_loop(t_mxw *mxw);
void	mxw_update(t_mxw *mxw);
bool	is_zombie_process(t_mxw *mxw);
void	mxw_exit(t_mxw *mxw);

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

	mxw = mxw_new_mxw(
		param.loop, param.loop_args, param.destroy, param.destroy_args);
	if (mxw == NULL)
		return (param.destroy(param.destroy_args), 1);
	err_no = ((int (*)(t_mxw *, void *))param.setup)(mxw, param.setup_args);
	if (err_no != 0)
		mxw_set_end(mxw);
	mlx_loop_hook(mxw->mlx, mxw_loop, mxw);
	mlx_loop(mxw->mlx);
	if (err_no != 0)
		mxw_destroy_mxw(mxw);
	return (0);
}

int	mxw_loop(t_mxw *mxw)
{
	if (mxw->is_exit == true)
		mxw_exit(mxw);
	else if (mxw->is_end == true)
		mxw->destroy(mxw->destroy_args);
	else
		mxw->loop(mxw, mxw->loop_args);
	mxw_update(mxw);
	return (0);
}

void	mxw_exit(t_mxw *mxw)
{
	mxw_int_clean_windows(mxw);
	mxw_destroy_mxw(mxw);
	exit(0);
}

void	mxw_update(t_mxw *mxw)
{
	if (mxw->window_list == NULL)
		mxw->idle_cnt += 1;
	else
		mxw->idle_cnt = 0;
	if (mxw->is_end == true)
		mxw->is_exit = true;
	if (is_zombie_process(mxw) == true)
		mxw->is_end = true;
}

bool	is_zombie_process(t_mxw *mxw)
{
	if (mxw->window_list == NULL)
	{
		mxw->idle_cnt += 1;
		if (mxw->idle_cnt > AUTO_CLOSE_TICK)
			return (true);
	}
	else
		mxw->idle_cnt = 0;
	return (false);
}
