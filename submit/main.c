/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:25:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/10 17:23:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "sl.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	t_sl_this			ls_this;
	int					result;
	t_mxw_start_param	mxw_start_param;

	sl_init_sl_this(&ls_this);
	mxw_start_param = (t_mxw_start_param){
		.setup = sl_setup,
		.loop = sl_loop,
		.destroy = sl_destroy,
		.setup_args = &ls_this,
		.loop_args = &ls_this,
		.destroy_args = &ls_this};
	result = mxw_start(mxw_start_param);
	if (result != 0)
		return (0);
	return (0);
}
