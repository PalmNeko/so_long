/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_clean_windows.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:21:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 23:27:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

void	mxw_int_clean_windows(t_mxw *mxw)
{
	while (mxw->window_list != NULL)
		mxw_destroy_window(mxw->window_list->content);
	return ;
}
