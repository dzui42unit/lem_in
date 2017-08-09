#include "lem_in.h"

void 	ft_print_rooms(t_room *head)
{
    t_room *st;

    st = head;
    while (st)
    {
        ft_printf("Name: %s\n", st->name);
        ft_printf("Id: %d\n", st->id);
        ft_printf("Start: %d\n", st->start);
        ft_printf("End: %d\n", st->end);
        ft_printf("Lem: %d\n", st->active_lem);
        ft_printf("\n");
        st = st->next;
    }
}

void	ft_print_path(t_lem *lem, t_room *head, t_path *head_path)
{
    int 	i;
    int 	j;
    int 	counter;
    t_path 	*current;

    counter = 0;
    current = head_path;
    ft_printf("\n");
    while (current)
    {
        i = 0;
        j = 0;
        ft_printf("path #%d\n", counter + 1);
        while (i < lem->size && current->path[i] != -1)
        {
            ft_printf("%s", ft_get_room(head, current->path[i])->name);
            if (j < current->length - 1)
            {
                ft_printf(" -> ");
                j++;
            }
            i++;
        }
        counter++;
        current = current->next;
        ft_printf("\n");
    }
    ft_printf("\n");
}

void    ft_error()
{
    ft_printf("ERROR\n");
    exit(0);
}

t_room	*ft_get_room(t_room *head, int pos)
{
	int     i;
    t_room *start;

    i = 0;
    start = head;
    while (i < pos && start->next)
    {
        start = start->next;
        i++;
    }
    return (start);
}
