/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:57:08 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 20:07:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

int mxw_put_image_to_window(t_mxw_window *window,
	t_mxw_image *img_ptr, int x, int y)
{
	return (mxw_put_image_to_image(window->img_buf, img_ptr, x, y));
}
