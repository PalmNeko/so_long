/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_int_sprite_sheet_to_player_flipbook.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:03:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:03:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "sl_int.h"

void	free_images(t_mxw_image **images, size_t size);

/**
 * @param points spritesheet points {x1, y1, x2, y2, .... xn, yn}
 */
t_mxw_flipbook *sl_int_sprite_sheet_to_player_flipbook(
	t_sl_this *sl, int *points, int size)
{
	t_mxw_image		**images;
	t_mxw_image		*resized;
	t_mxw_flipbook	*flipbook;
	int				index;

	images = (t_mxw_image **)malloc(sizeof(t_mxw_image *) * size);
	if (images == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		images[index] = mxw_cut_spritesheet(
			sl->mxw, sl->sprite_sheet, points[index * 2], points[index * 2 + 1]);
		if (images[index] == NULL)
			return (free_images(images, index), NULL);
		resized = mxw_resize_image(
			sl->mxw, images[index], sl->block_width, sl->block_height);
		if (resized == NULL)
			return (free_images(images, index), NULL);
		mxw_destroy_image(images[index]);
		images[index++] = resized;
	}
	flipbook = mxw_new_flipbook(sl->mxw, images, index);
	free_images(images, index);
	return (flipbook);
}

void	free_images(t_mxw_image **images, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		mxw_destroy_image(images[index]);
		index++;
	}
	free(images);
	return ;
}
