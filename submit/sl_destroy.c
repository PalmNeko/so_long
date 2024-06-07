/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:01:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 23:35:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	sl_destroy(void *destroy_arg)
{
	(void)destroy_arg;
	printf("%s\n", "destroy");
	return (0);
}
