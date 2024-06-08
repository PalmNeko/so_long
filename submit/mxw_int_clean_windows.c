/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_clean_windows.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:21:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 13:00:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

void	mxw_int_clean_windows(t_mxw *mxw)
{
	if (mxw == NULL)
		return;
	while (mxw->window_list != NULL)
		mxw_destroy_window(mxw->window_list->content);
	return ;
}
