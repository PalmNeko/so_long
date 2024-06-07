/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:13:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

int	mxw_destroy_body(t_mxw_body *body)
{
	mxw_destroy_flipbook(body->flipbook);
	free(body);
	return (0);
}
