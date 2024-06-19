/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:58:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 15:17:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include <stdbool.h>
# include <stdint.h>
# include "mxw_types.h"
# include "sl_param.h"
# include "sl_types.h"

int			sl_keyboard_handler(int keycode, t_sl_this *sl);
int			sl_loop(t_mxw *mxw, t_sl_this *sl);
int			sl_setup(t_mxw *mxw, t_sl_this *sl);
int	sl_destroy(t_sl_this *sl);

t_sl_player	*sl_new_player(t_sl_this *sl, int *points_xy[], int size);
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
void		sl_init_sl_this(t_sl_this *sl);
void 		sl_draw_image(t_sl_this *sl);
int			sl_move_player(t_sl_this *sl, t_sl_player *player, int x, int y);
void		sl_update_player(t_sl_player *player, size_t game_tick);
bool		sl_detect_collision_map(t_sl_map *map, int x, int y);
int			sl_load_assets(t_mxw *mxw, t_sl_this *sl);
void		*sl_foreach_map(t_sl_foreach_map_param *param);
void		sl_update_map(t_sl_this *sl);
void		sl_teleport_player(t_sl_this *sl, t_sl_player *player, int x, int y);
void		sl_print_move_counter(int move_count);
int			sl_count_block(t_sl_map	*map, t_sl_block_type block);
t_mxw_image	*sl_cut_spritesheet(
				t_mxw *mxw, t_mxw_spritesheet *sheet, int x, int y);
void 		sl_teleport_random_player(t_sl_this *sl, t_sl_player *player);
bool		sl_detect_collision_enemy(t_sl_player *player, t_sl_player *enemy);
void		sl_move_player_wrap(
				t_sl_this *sl, t_sl_player *player, t_direction direct);
uint32_t	sl_xorshift(uint32_t seed, uint32_t x);
void		sl_move_enemy_wrap(t_sl_this *sl, t_sl_player *enemy);
char		*sl_strerror(int sl_errno);
void		sl_put_error(int sl_errno);
void		*sl_foreach_ber(char **ber_data, int (*f)(), void *your_param, void *result);
bool		sl_validate_ber_map_width(char **ber_data);
bool		sl_validate_ber_map_height(char **ber_data);
bool		sl_validate_ber_map(char **ber_data);
bool		sl_validate_ber_end_newline(char **ber_data);
bool		sl_validate_ber_map_surrounded(char **ber_data);
int			sl_int_ber_chr_count(char **ber_data, char chr);
bool		sl_validate_ber_chr(char **ber_data, char *sets);
t_sl_point	sl_get_char_point(char **ber_data, char c);
bool		sl_validate_ber_reachable(char **ber_data);

#endif
