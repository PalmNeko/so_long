/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ber_fd_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:32:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 04:20:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "sl.h"
#include "libft.h"
#include "get_next_line.h"
#include "sl_errors.h"

t_list	*create_ber_list_fd(int fd);

t_sl_map	*sl_ber_fd_to_map(int fd)
{
	char		**ber_array;
	t_list		*ber_list;
	t_list		*tmp;
	size_t		size;
	t_sl_map	*map;

	errno = 0;
	ber_list = create_ber_list_fd(fd);
	if (errno != 0)
		return (NULL);
	else if (ber_list == NULL)
		return (sl_put_error(SL_EMAP_EMTPY), NULL);
	tmp = ft_lstnew(NULL);
	if (tmp == NULL)
		return (ft_lstclear(&ber_list, free), NULL);
	ft_lstadd_back(&ber_list, tmp);
	ber_array = (char **)ft_lst_to_array(ber_list, &size);
	if (ber_array == NULL)
		return (ft_lstclear(&ber_list, free), NULL);
	map = sl_ber_to_map(ber_array);
	ft_lstclear(&ber_list, free);
	free(ber_array);
	return (map);
}

t_list	*create_ber_list_fd(int fd)
{
	char		*line;
	t_list		*root;
	t_list		*iter;
	t_list		*new_lst;

	root = NULL;
	iter = root;
	errno = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_lst = ft_lstnew(line);
		if (new_lst == NULL)
			return (free(line), ft_lstclear(&root, free), NULL);
		ft_lstadd_back(&iter, new_lst);
		if (root == NULL)
			root = iter;
		iter = new_lst;
		line = get_next_line(fd);
	}
	if (errno != 0)
		return (ft_lstclear(&root, free), NULL);
	return (root);
}
