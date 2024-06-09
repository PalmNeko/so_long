/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:58:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 15:50:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mxw_types.h"
# include "sl_types.h"

typedef struct s_sl_player	t_sl_player;

typedef struct s_sl_this
{
	t_mxw				*mxw;
	t_mxw_window		*so_long_window;
	t_mxw_spritesheet	*sprite_sheet;
	t_sl_player			*player;
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
	enum e_direction	direction;
};

int			sl_keyboard_handler(int keycode, t_sl_this *vars);
int			sl_loop(t_mxw *mxw, t_sl_this *loop_args);
int			sl_setup(t_mxw *mxw, t_sl_this *setup_args);
int	sl_destroy(t_sl_this *destroy_arg);

t_sl_player	*sl_new_player(t_sl_this *sl);
void		sl_destroy_player(t_sl_player *player);
int			sl_load_assets(t_mxw *mxw, t_sl_this *sl);
int			sl_load(t_sl_this *sl);
void		sl_unload_assets(t_sl_this *sl);
void		sl_unload(t_sl_this *sl);
t_sl_map	*sl_ber_file_to_map(char *ber_filename);
t_sl_map	*sl_ber_fd_to_map(int fd);
t_sl_map	*sl_ber_to_map(char **ber_data);
bool		sl_validate_ber_map_size(char **ber_data);
int			sl_get_ber_height(char **ber_data);
int			sl_get_ber_width(char **ber_data);
void		sl_destroy_map(t_sl_map *map);


#endif
