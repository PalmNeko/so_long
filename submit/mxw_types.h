/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:25:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 12:16:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_TYPES_H
# define MXW_TYPES_H

# include <stdbool.h>

typedef struct s_mxw				t_mxw;
typedef struct s_mxw_image			t_mxw_image;
typedef struct s_mxw_window			t_mxw_window;
typedef struct s_mxw_window_list	t_mxw_window_list;
typedef struct s_mxw_spritesheet	t_mxw_spritesheet;
typedef struct s_mxw_flipbook		t_mxw_flipbook;
typedef struct s_mxw_body			t_mxw_body;

struct s_mxw {
	void			*mlx;
	t_mxw_window	*window_list;
	int				(*loop)(t_mxw *, void *loop_args);
	void			*loop_args;
	bool			is_end;
};

struct s_mxw_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct	s_mxw_window {
	void		*mlx_win;
	t_mxw_image	*img_buf;
	char		*title;
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

/**
 * struct parameter argument
*/
typedef struct s_mxw_cut_image_param {
	t_mxw		*mxw;
	t_mxw_image	*image;
	int			x;
	int			y;
	int			width;
	int			height;
}	t_mxw_cut_image_param;

/**
 * @param image iterate image.
 * @param your_param you want to use param.
 * @param f your each function
 * 			int (*f)(void *your_param, t_mxw_fip_param *param)
 * @param offset_x start pixel point of image.
 * @param offset_y start pixel point of image.
 * @param width	loop width
 * @param height loop height
 * @param result The data here is passed to each loop and set
 * 	as the last return value.
*/
typedef struct s_mxw_foreach_image_param {
	t_mxw_image	*image;
	void		*your_param;
	int			(*f)();
	int			offset_x;
	int			offset_y;
	int			width;
	int			height;
	void		*result;
}	t_mxw_foreach_image_param;

/**
 * @param image_x image point
 * @param image_y image point
 * @param index_x index point
 * @param index_y index point
 * @param image image data
 * @param result please store your calculate result.
*/
typedef struct s_mxw_fip_param {
	int			image_x;
	int			image_y;
	int			index_x;
	int			index_y;
	t_mxw_image	*image;
	void		*result;
}	t_mxw_fip_param;

typedef enum e_mxw_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_mxw_event;

enum {
	KEY_0=29,
	KEY_1=18,
	KEY_2=19,
	KEY_3=20,
	KEY_4=21,
	KEY_5=23,
	KEY_6=22,
	KEY_7=26,
	KEY_8=28,
	KEY_9=25,
	KEY_A=0,
	KEY_B=11,
	KEY_C=8,
	KEY_D=2,
	KEY_E=14,
	KEY_F=3,
	KEY_G=5,
	KEY_H=4,
	KEY_I=34,
	KEY_J=38,
	KEY_K=40,
	KEY_L=37,
	KEY_M=46,
	KEY_N=45,
	KEY_O=31,
	KEY_P=35,
	KEY_Q=12,
	KEY_R=15,
	KEY_S=1,
	KEY_T=17,
	KEY_U=32,
	KEY_V=9,
	KEY_W=13,
	KEY_X=7,
	KEY_Y=16,
	KEY_Z=6,
	KEY_RETURN=36,
	KEY_TAB=48,
	KEY_LCTRL=256,
	KEY_LCMD=259,
	KEY_LOPT=261,
	KEY_RCMD=260,
	KEY_ROPT=262,
	KEY_LEFT_ARROW=123,
	KEY_RIGHT_ARROW=124,
	KEY_UP_ARROW=126,
	KEY_DOWN_ARROW=125,
	KEY_LSHIFT=257,
	KEY_RSHIFT=258,
	KEY_CAPS=272,
	KEY_FN=279,
	KEY_BACK=51,
	KEY_ESC=53,
};

#endif
