/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ber_fd_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:32:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 14:42:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sl.h"
#include "libft.h"
#include "get_next_line.h"

t_list	*create_ber_list_fd(int fd);

t_sl_map	*sl_ber_fd_to_map(int fd)
{
	char		*ber_array;
	t_list		*ber_list;
	t_list		*tmp;
	size_t		size;
	t_sl_map	*map;

	ber_list = create_ber_list_fd(fd);
	if (ber_list == NULL)
		return (NULL);
	tmp = ft_lstnew(NULL);
	if (tmp == NULL)
		return (ft_lstclear(ber_list, free), NULL);
	ft_lstadd_back(&ber_list, tmp);
	ber_array = ft_lst_to_array(ber_list, &size);
	if (ber_array == NULL);
		return (ft_lstclear(ber_list, free), NULL);
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
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_lst = ft_lstnew(line);
		if (new_lst == NULL)
			return (free(line), ft_lstclear(root, free), NULL);
		ft_lstadd_back(&iter, new_lst);
		if (root == NULL)
			root = iter;
		iter = new_lst;
		line = get_next_line(fd);
	}
	return (root);
}
