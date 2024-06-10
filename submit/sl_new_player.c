/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:25:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 02:10:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "sl.h"
#include "libft.h"

t_mxw_flipbook *sprite_sheet_to_player_flipbook(t_sl_this *sl, int *points, int size);
void	free_images(t_mxw_image **images, size_t size);
int		sl_assign_player_flipbook(t_sl_player *player, t_sl_this *sl);

t_sl_player	*sl_new_player(t_sl_this *sl)
{
	t_sl_player *player;

	player = (t_sl_player *)malloc(sizeof(t_sl_player));
	if (player == NULL)
		return (NULL);
	if (sl_assign_player_flipbook(player, sl) != 0)
		return (free(player), NULL);
	player->direction = RIGHT;
	player->now_flipbook = &player->right_flipbook;
	player->x = 0;
	player->y = 0;
	player->now_x = 0;
	player->now_y = 0;
	player->aim_x = 0;
	player->aim_y = 0;
	return (player);
}

int	sl_assign_player_flipbook(t_sl_player *player, t_sl_this *sl)
{
	int				index;
	int				**points_xy;
	t_mxw_flipbook	***flipbooks;

	points_xy = (int *[]){
		(int []){13, 0, 14, 0, 15, 0, 16, 0},
		(int []){13, 1, 14, 1, 15, 1, 16, 1},
		(int []){13, 2, 14, 2, 15, 2, 16, 2},
		(int []){13, 3, 14, 3, 15, 3, 16, 3}};
	flipbooks = (t_mxw_flipbook **[4]){
		&player->down_flipbook, &player->up_flipbook,
		&player->right_flipbook, &player->left_flipbook};
	index = 0;
	while (index < 4)
	{
		*flipbooks[index] = sprite_sheet_to_player_flipbook(sl, points_xy[index], 4);
		if (*flipbooks[index] == NULL)
		{
			while (index >= 0)
			{
				mxw_destroy_flipbook(*flipbooks[index]);
				index--;
			}
			return (-1);
		}
		index++;
	}
	return (0);
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

/**
 * @param points spritesheet points {x1, y1, x2, y2, .... xn, yn}
 */
t_mxw_flipbook *sprite_sheet_to_player_flipbook(t_sl_this *sl, int *points, int size)
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
