/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:50:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 21:40:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_INT_TYPES_H
# define MXW_INT_TYPES_H

typedef struct s_mxw_event_handler	t_mxw_event_handler;
struct s_mxw_event_handler
{
	int		(*handler)();
	void	*param;
};

#endif
