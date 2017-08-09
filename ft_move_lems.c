#include "lem_in.h"

t_room   *ft_where_the_ant_is(t_room *head, uintmax_t active_lem)
{
    t_room  *start;

    start = head;
    while (start)
    {
        if (active_lem == start->active_lem)
            return (start);
        start = start->next;
    }
    return (head);
}

int     ft_position_in_path(t_lem *lem, t_path *path, int room)
{
    int     i;

    i = 0;
    while (i < lem->size && path->path[i] != -1)
    {
        if (path->path[i] == room)
            return (i);
        i++;
    }
    return (-1);
}

void    ft_move_lem(t_lem *lem, t_path *path, t_room *head_room)
{
    uintmax_t   init;
    uintmax_t   index;
    int         pos;
    t_room      *next_room;
    t_room      *current_room;
    t_path      *start;

    init = lem->ants;
    while (lem->ants > 0)
    {
        index = (init - lem->ants) + 1;
        while (index <= init)
        {
            start = path;
            current_room = ft_where_the_ant_is(head_room, index);
            while (start)
            {
                pos = ft_position_in_path(lem, start, current_room->id);
                if (pos != -1)
                {
                    pos++;
                    next_room = ft_get_room(head_room, start->path[pos]);
                    if (next_room->active_lem == 0)
                    {
                        current_room->active_lem = 0;
                        next_room->active_lem = index;
                        ft_printf("L%d-", index);
                        ft_printf("%s ", next_room->name);
                        if (next_room->id == lem->size - 1)
                        {
                            lem->ants--;
                            next_room->active_lem = 0;
                        }
                        break ;
                    }
                }
                start = start->next;
            }
            index++;
        }
        ft_printf("\n");
    }
}