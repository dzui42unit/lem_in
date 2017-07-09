#include "lem_in.h"

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
    i = 0;
    ft_printf("\n   Visited:\n\n");
    while (i < lem->size)
    {
        ft_printf("%3d\n", lem->visited[i]);
        i++;
    }
}
