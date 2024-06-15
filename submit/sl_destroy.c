/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:01:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 19:37:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sl.h"

int	sl_destroy(t_sl_this *sl)
{
	sl_unload(sl);
	printf("%s\n", "destroy");
	return (0);
}
