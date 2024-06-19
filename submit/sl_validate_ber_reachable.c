/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_reachable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 15:22:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

char    **sl_clone_ber_data(char **ber_data);
void    sl_destroy_ber_data(char **ber_data);
void	sl_fill_road(char **ber_data, t_sl_point pos, char fill_value);

bool	sl_validate_ber_reachable(char **ber_data)
{
    t_sl_point  player_pos;
    char        **cloned_ber_data;
    bool        is_reachable;

    cloned_ber_data = sl_clone_ber_data(ber_data);
    if (cloned_ber_data == NULL)
        return (NULL);
    player_pos = sl_get_char_point(ber_data, 'P');
    sl_fill_road(cloned_ber_data, player_pos, '1');
    is_reachable = sl_validate_ber_chr(cloned_ber_data, "10");
    sl_destroy_ber_data(cloned_ber_data);
    return (is_reachable);
}

void	sl_fill_road(char **ber_data, t_sl_point pos, char fill_value)
{
    if (pos.y < 0 || ber_data[pos.y] == NULL)
        return ;
    if (pos.x < 0 || ber_data[pos.y][pos.x] == '\0')
        return ;
    if (! ft_includes(ber_data[pos.y][pos.x], "0PEC"))
        return ;
    ber_data[pos.y][pos.x] = fill_value;
    sl_fill_road(
        ber_data, (t_sl_point){.x = pos.x - 1, .y = pos.y}, fill_value);
    sl_fill_road(
        ber_data, (t_sl_point){.x = pos.x + 1, .y = pos.y}, fill_value);
    sl_fill_road(
        ber_data, (t_sl_point){.x = pos.x, .y = pos.y - 1}, fill_value);
    sl_fill_road(
        ber_data, (t_sl_point){.x = pos.x, .y = pos.y + 1}, fill_value);
}

char    **sl_clone_ber_data(char **ber_data)
{
    char    **cloned;
    int     height;
    int     index;

    height = sl_get_ber_height(ber_data);
    if (height < 0)
        return (NULL);
    cloned = (char **)ft_calloc(height + 1, sizeof(char *));
    if (cloned == NULL)
        return (NULL);
    index = 0;
    while (index < height)
    {
        cloned[index] = ft_strdup(ber_data[index]);
        if (cloned[index] == NULL)
        {
            sl_destroy_ber_data(ber_data);
            return (NULL);
        }
        index++;
    }
    return (cloned);
}

void    sl_destroy_ber_data(char **ber_data)
{
    int index;

    index = 0;
    while(ber_data[index] != NULL)
    {
        free(ber_data[index]);
        index++;
    }
    free(ber_data);
}
