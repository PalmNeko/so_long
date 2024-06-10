/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:09:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 18:01:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include "sl_conf.h"
# include "mxw.h"

typedef struct s_sl_player		t_sl_player;
typedef enum e_sl_block_type	t_sl_block_type;
typedef struct s_sl_map		t_sl_map;
typedef enum s_sl_background	t_sl_background;


struct s_sl_map {
	t_sl_block_type	**fields;
	int				width;
	int				height;
};

enum e_sl_block_type {
	WALL,
	ROAD,
};

typedef struct s_sl_this
{
	t_mxw				*mxw;
	t_mxw_window		*so_long_window;
	t_mxw_spritesheet	*sprite_sheet;
	t_mxw_image			*bg_block[MAX_BG_BLOCK];
	t_mxw_image			*background;
	int					block_width;
	int					block_height;
	t_sl_map			*map;
	t_sl_player			*player;
	char				*ber_filename;
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

enum s_sl_background
{
	BG_NONE,
	BG_WALL,
	BG_GRASS,
	BG_ROAD,
};

#endif
