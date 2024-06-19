/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ber_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:35:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 14:37:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sl.h"

static t_sl_block_type	*sl_ber_line_to_block(
	char *ber_line, const int width);
static t_sl_block_type	sl_ber_chr_to_block(char ber_chr);

/**
 * @param ber_data NULL terminated string array.
 */
t_sl_map	*sl_ber_to_map(char **ber_data)
{
	t_sl_map	*map;
	int			index;
	int			height;
	int			width;

	if (sl_validate_ber_map(ber_data) == false)
		return (NULL);
	height = sl_get_ber_height(ber_data);
	width = sl_get_ber_width(ber_data);
	if (height < 0 || width < 0)
		return (NULL);
	map = (t_sl_map *)malloc(sizeof(t_sl_map));
	map->fields = (t_sl_block_type **)ft_calloc(
		height, sizeof(t_sl_block_type *));
	if (map == NULL)
		return (NULL);
	map->height = height;
	map->width = width;
	index = 0;
	while (index < map->height)
	{
		map->fields[index] = sl_ber_line_to_block(
			ber_data[index], map->width);
		if (map->fields[index] == NULL)
			return (sl_destroy_map(map), NULL);
		index++;
	}
	map->player_point = sl_get_char_point(ber_data, PLAYER_CHARACTER);
	map->goal_point = sl_get_char_point(ber_data, GOAL_CHARACTER);
	return (map);
}

static t_sl_block_type	*sl_ber_line_to_block(
	char *ber_line, const int width)
{
	size_t			index;
	t_sl_block_type	*blocks;

	if (width < 0)
		return (NULL);
	blocks = (t_sl_block_type *)malloc(sizeof(t_sl_block_type) * width);
	if (blocks == NULL)
		return (NULL);
	index = 0;
	while (index < (size_t)width)
	{
		blocks[index] = sl_ber_chr_to_block(ber_line[index]);
		index++;
	}
	return (blocks);
}

static t_sl_block_type	sl_ber_chr_to_block(char ber_chr)
{
	if (ber_chr == '0')
		return (ROAD);
	else if (ber_chr == '1')
		return (WALL);
	else if (ber_chr == 'C')
		return (ITEM);
	else if (ber_chr == 'E')
		return (GOAL);
	else if (ber_chr == 'P')
		return (PLAYER);
	else
		return (NONE);
}
