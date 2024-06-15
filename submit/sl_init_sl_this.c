/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_sl_this.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:05:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 19:39:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sl_types.h"
#include "libft.h"

void	sl_init_sl_this(t_sl_this *sl)
{
	ft_bzero(sl, sizeof(t_sl_this));
}
