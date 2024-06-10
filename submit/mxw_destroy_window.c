/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:25:25 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 17:00:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "libft.h"

void	ft_voidnop()
{
	return ;
}

void	mxw_destroy_window(t_mxw_window *win)
{
	if (win == NULL)
		return ;
	ft_lstdel_content(&win->mxw->window_list, win, ft_voidnop);
	mxw_destroy_image(win->img_buf);
	if (win->has_mlx_win == true)
		mlx_destroy_window(win->mxw->mlx, win->mlx_win);
	free(win);
}
