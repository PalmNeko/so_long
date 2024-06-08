/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:03:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 17:10:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*debug_malloc(size_t size, char *filename, int line)
{
	void	*return_ptr;

	return_ptr = malloc(size);
	fprintf(stderr, "%p - %s:%d size:%zd\n", return_ptr, filename, line, size);
	return (return_ptr);
}
