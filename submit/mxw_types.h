/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 23:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_TYPES_H
# define MXW_TYPES_H

# include "libft.h"
# include "mxw_int_types.h"
# include <stdbool.h>
# include <X11/X.h>

# define MXW_EVENT_HANDLER 32
// 36 because LASTEvent(ref. X11/X.h). for fuckin' norminette.
# define MAX_EVENT_CNT 36

typedef struct s_mxw				t_mxw;
typedef struct s_mxw_image			t_mxw_image;
typedef struct s_mxw_window			t_mxw_window;
typedef struct s_mxw_window_list	t_mxw_window_list;
typedef struct s_mxw_spritesheet	t_mxw_spritesheet;
typedef struct s_mxw_flipbook		t_mxw_flipbook;
typedef struct s_mxw_body			t_mxw_body;

/**
 * @attention Don't touch is_end and is_exit! you can use mxw_set_end function.
*/
struct s_mxw {
	void			*mlx;
	t_list			*window_list;
	int				(*loop)(t_mxw *, void *loop_args);
	void			*loop_args;
	int				(*destroy)(void *destroy_args);
	void			*destroy_args;
	bool			is_end;
	bool			is_exit;
	long			idle_cnt;
};

struct s_mxw_image {
	t_mxw	*mxw;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct	s_mxw_window {
	t_mxw				*mxw;
	void				*mlx_win;
	t_mxw_image			*img_buf;
	char				*title;
	int					width;
	int					height;
	t_mxw_event_handler	event_handlers[MAX_EVENT_CNT][MXW_EVENT_HANDLER];
	int					event_handlers_cnt[MAX_EVENT_CNT];
	bool				has_mlx_win;
};

struct s_mxw_window_list {
	t_mxw_window		*mxw_window;
	t_mxw_window_list	*next;
};

/**
 * @param t_mxw_image sprite sheet image
 * @param image_width an image width,
 * @param image_height an image height,
 * @param image_count image_count,
*/
struct s_mxw_spritesheet {
	t_mxw_image	*sprite_sheet;
	int			image_width;
	int			image_height;
};

struct s_mxw_flipbook {
	t_mxw_image	**flip_book;
	int			size;
	int			iter;
};

struct s_mxw_body {
	t_mxw_flipbook	*flipbook;
	int				x;
	int				y;
};

#endif
