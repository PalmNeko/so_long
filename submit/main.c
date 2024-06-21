/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:25:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 23:48:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "sl.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_sl_this			ls_this;
	int					result;
	t_mxw_start_param	mxw_start_param;

	sl_init_sl_this(&ls_this);
	if (argc != 2)
		return (0);
	ls_this.ber_filename = argv[1];
	mxw_start_param = (t_mxw_start_param){
		.setup = sl_setup,
		.loop = sl_loop,
		.destroy = sl_destroy,
		.setup_args = &ls_this,
		.loop_args = &ls_this,
		.destroy_args = &ls_this};
	result = mxw_start(mxw_start_param);
	if (result != 0)
		return (1);
	return (0);
}
