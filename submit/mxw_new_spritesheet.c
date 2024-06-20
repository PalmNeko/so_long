/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_spritesheet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:27:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 01:07:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

/**
 * @brief create new sprite sheet instance.
 * @param spritesheet sprite sheet image
 * @param img_width	an splitted image width.
 * @param img_width	an splitted image width.
 * @return new sprite sheet instance in Memory.
 *         NULL if an error occurred or can't split width of spritesheet
 *         with img_width or height of spritesheet with img_height.
 * @attention spritesheet argument is not copied.
*/
t_mxw_spritesheet	*mxw_new_spritesheet(
	t_mxw *mxw,
	t_mxw_image *spritesheet,
	int img_width,
	int img_height)
{
	t_mxw_spritesheet	*sprite_sheet;

	if (spritesheet->width % img_width != 0
		|| spritesheet->height % img_height != 0)
		return (NULL);
	sprite_sheet = (t_mxw_spritesheet *)malloc(sizeof(t_mxw_spritesheet));
	if (sprite_sheet == NULL)
		return (NULL);
	sprite_sheet->sprite_sheet = mxw_clone_image(mxw, spritesheet);
	if (sprite_sheet->sprite_sheet == NULL)
		return (free(sprite_sheet), NULL);
	sprite_sheet->image_width = img_width;
	sprite_sheet->image_height = img_height;
	return (sprite_sheet);
}
