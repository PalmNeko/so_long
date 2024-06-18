/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:23:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 05:23:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ERRORS_H
# define SL_ERRORS_H

enum e_sl_errors {
	SL_ENONE,
	SL_EMAP_WIDTH,
	SL_EMAP_PARSE,
	SL_EMAP_CANT_REACH,
	SL_EMAP_DUPLICATED_PLAYER,
	SL_EMAP_DUPLICATED_EXIT,
	SL_EMAP_MUST_SURROUND,
	SL_EMAP_MUST_INCLUDE_WALL,
	SL_EMAP_MUST_INCLUDE_COLLECTIBLE,
	SL_EMAP_MUST_INCLUDE_FREESPACE,
	SL_EMAP_MUST_INCLUDE_PLAYER,
	SL_EMAP_MUST_INCLUDE_EXIT,
	SL_EMAP_MUST_END_NEWLINE,
};

#endif
