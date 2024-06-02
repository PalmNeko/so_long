/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:19:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 19:15:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include "mxw.h"

int	mxw_loop(t_mxw *mxw);

/**
 * mxw_start
 * run setup -> run loop
 */
int	mxw_start(
		int (*setup)(),
		int (*loop)(),
		void *setup_args,
		void *loop_args)
{
	t_mxw	*mxw;
	int		err_no;

	mxw = mxw_init();
	if (mxw == NULL)
		return (1);
	err_no = ((int (*)(t_mxw *, void *setup_args))setup)(mxw, setup_args);
	if (err_no != 0)
		return (err_no);
	mxw->loop = (int (*)(t_mxw *, void *loop_args))loop;
	mxw->loop_args = loop_args;
	mlx_loop_hook(mxw->mlx, mxw_loop, mxw);
	mlx_loop(mxw->mlx);
	return (0);
}

int	mxw_loop(t_mxw *mxw)
{
	mxw->loop(mxw, mxw->loop_args);
	if (mxw->is_end == true)
	{
		/**
		 * 終了処理を作成して終了 
		 */
		mxw_destroy_mxw(mxw);
		exit(0);
	}
	/* 一定時間ウィンドウが作成されなかったら終了する処理を入れる。*/
	return (0);
}
