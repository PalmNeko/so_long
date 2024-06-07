/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_spritesheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:47:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 18:52:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

/**
 * @brief free spritesheet instance.
 * @param spritesheet spritesheet instance.
 * @return not used. always zero.
 * @attention image of spritesheet instance will not be freed.
*/
void	mxw_destroy_spritesheet(t_mxw_spritesheet *spritesheet)
{
	mxw_destroy_image(spritesheet->sprite_sheet);
	free(spritesheet);
}
