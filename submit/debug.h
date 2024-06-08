/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:05:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 17:09:27 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG
# ifndef DEBUG_H
#  define DEBUG_H

#  include <stdlib.h>

#  define malloc(size) debug_malloc(size, __FILE__, __LINE__)

void	*debug_malloc(size_t size, char *filename, int line);

# endif
#endif
