/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_mxw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:50:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 19:56:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "libft.h"

void	mxw_destroy_mxw(t_mxw *mxw)
{
	while (mxw->window_list != NULL)
		mxw_destroy_window(mxw->window_list->content);
	free(mxw);
	return ;
}
