/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:09:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 14:44:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

typedef enum e_sl_block_type	t_sl_block_type;
typedef struct s_sl_map		t_sl_map;

struct s_sl_map {
	t_sl_block_type	**fields;
	int				width;
	int				height;
};

enum e_sl_block_type {
	WALL,
	ROAD,
};

#endif
