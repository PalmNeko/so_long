/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_mxw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:50:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/22 00:11:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw_int.h"
#include "libft.h"

void	mxw_destroy_mxw(t_mxw *mxw)
{
	if (mxw->destroy != NULL)
		mxw->destroy(mxw->destroy_args);
	mxw_int_clean_windows(mxw);
	free(mxw->mlx);
	free(mxw);
	return ;
}
