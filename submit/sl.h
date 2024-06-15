/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:58:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 14:56:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include <stdbool.h>
# include "mxw_types.h"
# include "sl_types.h"

int			sl_keyboard_handler(int keycode, t_sl_this *vars);
int			sl_loop(t_mxw *mxw, t_sl_this *loop_args);
int			sl_setup(t_mxw *mxw, t_sl_this *setup_args);
int	sl_destroy(t_sl_this *destroy_arg);

t_sl_player	*sl_new_player(t_sl_this *sl);
void		sl_destroy_player(t_sl_player *player);
int			sl_load(t_sl_this *sl);
void		sl_unload(t_sl_this *sl);
t_sl_map	*sl_ber_file_to_map(char *ber_filename);
t_sl_map	*sl_ber_fd_to_map(int fd);
t_sl_map	*sl_ber_to_map(char **ber_data);
bool		sl_validate_ber_map_size(char **ber_data);
int			sl_get_ber_height(char **ber_data);
int			sl_get_ber_width(char **ber_data);
void		sl_destroy_map(t_sl_map *map);
void		sl_init_sl_this(t_sl_this *this);
void 		sl_draw_image(t_sl_this *this);
void		sl_move_player(t_sl_this *sl, int x, int y);
void		sl_update_player(t_sl_player *player, size_t game_tick);
bool		sl_detect_collision_map(t_sl_map *map, int x, int y);

#endif
