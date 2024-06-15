/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:09:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:50:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TYPES_H
# define SL_TYPES_H

# include "sl_conf.h"
# include "mxw.h"

typedef struct s_sl_player		t_sl_player;
typedef enum e_sl_block_type	t_sl_block_type;
typedef struct s_sl_map		t_sl_map;
typedef enum s_sl_background	t_sl_background;
typedef struct s_sl_point	t_sl_point;

struct s_sl_point {
	int x;
	int y;
};

struct s_sl_map {
	t_sl_block_type	**fields;
	t_sl_point		player_point;
	t_sl_point		goal_point;
	t_sl_point		*collect_points;
	int				width;
	int				height;
};

enum e_sl_block_type {
	NONE,
	WALL,
	ROAD,
	GOAL,
	PLAYER,
	ITEM,
};

enum s_sl_background
{
	BG_NONE,
	BG_WALL,
	BG_GRASS,
	BG_ROAD,
	BG_GOAL,
	MAX_BG_BLOCK,
};

typedef struct s_sl_this
{
	t_mxw				*mxw;
	t_mxw_window		*so_long_window;
	t_mxw_spritesheet	*sprite_sheet;
	t_mxw_image			*bg_block[MAX_BG_BLOCK];
	t_mxw_image			*background;
	t_mxw_image			*img_item;
	t_mxw_image			*counter_header;
	int					block_width;
	int					block_height;
	int					item_count;
	int					move_count;
	int					max_item_count;
	t_sl_point			camera_point;
	t_sl_map			*map;
	t_sl_player			*player;
	t_sl_player			*enemy;
	char				*ber_filename;
	size_t				game_tick;
	size_t				game_tick_reset_time;
}	t_sl_this;

enum e_direction
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

struct s_sl_player
{
	t_mxw_flipbook		*up_flipbook;
	t_mxw_flipbook		*down_flipbook;
	t_mxw_flipbook		*left_flipbook;
	t_mxw_flipbook		*right_flipbook;
	t_mxw_flipbook		**now_flipbook;
	int					x;
	int					y;
	int					now_x;
	int					now_y;
	int					aim_x;
	int					aim_y;
	enum e_direction	direction;
};

#endif
