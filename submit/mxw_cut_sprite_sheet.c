/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_cut_sprite_sheet.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:51:49 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 15:05:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mxw.h"

t_mxw_image	*mxw_cut_spritesheet(t_mxw *mxw, t_mxw_spritesheet *sheet, int x, int y)
{
	t_mxw_image	*image;
	
	if (x < 0 || y < 0)
		return (NULL);
	else if (y * sheet->image_height > sheet->sprite_sheet->height)
		return (NULL);
	else if (x * sheet->image_width > sheet->sprite_sheet->width)
		return (NULL);
	image = mxw_cut_image((t_mxw_cut_image_param []){{
		.mxw = mxw,
		.image = sheet->sprite_sheet,
		.height = sheet->image_height,
		.width = sheet->image_width,
		.x = x * sheet->image_width,
		.y = y * sheet->image_height,
	}});
	return (image);
}
