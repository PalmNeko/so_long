/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_fliipbook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:17:10 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:17:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

static t_mxw_image	**__clone_images(
						t_mxw *mxw, t_mxw_image **images, int size);

t_mxw_flipbook	*mxw_new_flipbook(t_mxw *mxw, t_mxw_image **images, int size)
{
	t_mxw_image		**cloned_images;
	t_mxw_flipbook	*flip_book;
	int				index;

	flip_book = (t_mxw_flipbook *)malloc(sizeof(t_mxw_flipbook *) * size);
	if (flip_book == NULL)
		return (NULL);
	cloned_images = (t_mxw_image **)malloc(sizeof(t_mxw_image *) * size);
	if (cloned_images == NULL)
		return (NULL);
	index = 0;
	cloned_images = __clone_images(mxw, images, size);
	flip_book->flip_book = cloned_images;
	flip_book->size = size;
	flip_book->iter = 0;
	return (flip_book);
}

static t_mxw_image	**__clone_images(
		t_mxw *mxw, t_mxw_image **images, int size)
{
	int			index;
	t_mxw_image	**cloned_images;

	cloned_images = (t_mxw_image **)malloc(sizeof(t_mxw_image *) * size);
	if (cloned_images == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		cloned_images[index] = mxw_clone_image(mxw, images[index]);
		if (cloned_images[index] == NULL)
		{
			while (index > 0)
			{
				mxw_destroy_image(mxw, cloned_images[index]);
				index--;
			}
			mxw_destroy_image(mxw, cloned_images[index]);
			return (NULL);
		}
		index++;
	}
	return (cloned_images);
}
