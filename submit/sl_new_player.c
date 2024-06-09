/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:25:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 17:01:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "sl.h"
#include "libft.h"

t_sl_player	*sl_new_player(t_sl_this *sl)
{
	t_mxw_image	*tmp[5];
	t_free_args frees[15];
	t_sl_player *player;
	int			index;
	int			free_cnt;

	free_cnt = 0;
	index = 0;
	while (index < 5)
	{
		tmp[index] = mxw_cut_spritesheet(sl->mxw, sl->sprite_sheet, 12 + index, 0);
		if (tmp[index] == NULL)
			return (ft_free_iter(frees, free_cnt), NULL);
		frees[free_cnt++] = (t_free_args){
			.arg = tmp[index], .free_func = mxw_destroy_image};
		free_cnt++, index++;
	}
	player = (t_sl_player *)malloc(sizeof(t_sl_player));
	if (player == NULL)
		return (ft_free_iter(frees, free_cnt), NULL);
	frees[free_cnt++] = (t_free_args){.arg = player, .free_func = free};
	player->up_flipbook = mxw_new_flipbook(sl->mxw, tmp, index);
	player->left_flipbook = NULL;
	if (player->up_flipbook == NULL)
		return (ft_free_iter(frees, free_cnt), NULL);
	frees[free_cnt++] = (t_free_args){
		.arg = player->up_flipbook, .free_func = mxw_destroy_flipbook};
	player->right_flipbook = NULL;
	player->down_flipbook = NULL;
	player->direction = RIGHT;
	player->now_flipbook = &player->up_flipbook;
	player->x = 0;
	player->y = 0;
	index = 0;
	while (index < 5)
		mxw_destroy_image(tmp[index++]);
	return (player);
}
