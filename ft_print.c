#include "lem_in.h"

void 	ft_print_rooms(t_room *head)
{
    t_room *st;

    st = head;
    ft_printf("\n\n");
    while (st)
    {
        ft_printf("Name: %s\n", st->name);
        ft_printf("Id: %d\n", st->id);
        ft_printf("Start: %d\n", st->start);
        ft_printf("End: %d\n", st->end);
        ft_printf("\n");
        st = st->next;
    }
}

void    ft_print_visited(t_lem *lem, int *visited)
{
    int i;

    i = 0;
    ft_printf("VISITED:\n");
    while (i < lem->size && visited[i] != -1)
    {
        ft_printf("%d ", visited[i]);
        i++;
    }
    ft_printf("\n");
}

void	ft_print_path(t_lem *lem, t_room *head, t_path *head_path)
{
    int 	i;
    int 	j;
    int 	counter;
    t_path 	*current;

    counter = 0;
    current = head_path;
    while (current)
    {
        i = 0;
        j = 0;
        ft_printf("path #%d\n", counter + 1);
        while (i < lem->size && current->path[i] != -1)
        {
            ft_printf("%d", current->path[i]);
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

void    ft_print_list(t_path *head, t_lem *lem)
{
    t_path *current;
    int     i;
    int     k;

    i = 0;

    current = head;
    while (current != NULL)
    {
        ft_printf("PATH # %d\n\n", i + 1);
        k = 0;

        ft_printf("SIZE OF PATH: %d\n\n", current->length);

        while (k < lem->size)
        {
            ft_printf("%d\n", current->path[k]);
            k++;
        }
        ft_printf("\n");
        current = current->next;
        i++;
    }
}

void    ft_error()
{
    ft_printf("ERROR\n");
    exit(0);
}
void 	ft_print_needed_node(t_lem *lem, t_room *head, int pos)
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
    ft_printf("%s", start->name);
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

void    ft_print_adjecency_matrix(t_lem *lem)
{
    int i;
    int j;

    ft_printf("  Adjecency Matrix\n\n");
    i = 0;
    while (i < lem->size)
    {
        j = 0;
        while (j < lem->size)
        {
            ft_printf("%3d", lem->adj_matrix[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}
