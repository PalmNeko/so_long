/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:47:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 13:01:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

void	mxw_destroy_body(t_mxw_body *body)
{
	if (body == NULL)
		return ;
	mxw_destroy_flipbook(body->flipbook);
	free(body);
}
