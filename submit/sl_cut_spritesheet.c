/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cut_spritesheet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:20:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:20:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "sl_conf.h"

t_mxw_image	*sl_cut_spritesheet(
	t_mxw *mxw, t_mxw_spritesheet *sheet, int x, int y)
{
	t_mxw_image	*tmp;
	t_mxw_image	*resized;

	tmp = mxw_cut_spritesheet(mxw, sheet, x, y);
	if (tmp == NULL)
		return (NULL);
	resized = mxw_resize_image(
			mxw, tmp, tmp->width * IMAGE_SCALE, tmp->height * IMAGE_SCALE);
	mxw_destroy_image(tmp);
	return (resized);
}
