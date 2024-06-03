/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:25:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/02 21:10:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "so_long.h"

int	main(void)
{
	t_sl_this	ls_this;
	int			result;

	result = mxw_start(sl_setup, sl_loop, &ls_this, &ls_this);
	if (result != 0)
		return (1);
	return (0);
}
