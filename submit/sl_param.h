/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 16:06:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_PARAM_H
# define SL_PARAM_H

# include "mxw_types.h"
# include "sl_types.h"

typedef struct s_sl_foreach_map_param	t_sl_foreach_map_param;
typedef struct s_sl_fmp_param			t_sl_fmp_param;

struct s_sl_foreach_map_param {
	t_sl_map	*map;
	void		*your_param;
	int			(*f)();
	void		*result;
};

struct s_sl_fmp_param {
	t_sl_map	*map;
	int			index_x;
	int			index_y;
	void		*result;
};

#endif
