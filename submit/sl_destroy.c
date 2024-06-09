/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:01:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 17:34:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "sl.h"

int	sl_destroy(t_sl_this *destroy_arg)
{
	sl_unload(destroy_arg);
	printf("%s\n", "destroy");
	return (0);
}
