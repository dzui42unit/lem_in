#include "lem_in.h"

void    ft_find_prev_list_node(t_room **head, t_room **node, t_room **assign)
{
    t_room *current;

    current = *head;
    while (current)
    {
        ft_printf("move\n");
        if (current->next && current->next == *node)
        {
            ft_printf("FLSFKLKSDJLSDKFJ\n\n");
            *assign = *node;
            ft_printf("%s", (*assign)->name);
            return ;
        }
        current = current->next;
    }
}

void    ft_set_start_end(t_room **head)
{
    t_room *start_node;
    t_room *head_prev;
    t_room *end_prev;
    t_room *end_node;
    t_room *s_prev;
    t_room *e_prev;
    t_room *current;
    t_room *end;

    end = *head;
    while (end->next)
    {
        end = end->next;
    }
    start_node = *head;
    while (start_node)
    {
        if (start_node->start)
            break ;
        start_node = start_node->next;
    }
    current = *head;
    s_prev = NULL;
    while (current)
    {
        if (current->next && current->next == start_node)
        {
            s_prev = current;
            break ;
        }
        current = current->next;
    }
    if (start_node != *head)
    {
        s_prev->next = start_node->next;
        start_node->next = *head;
        *head = start_node;
        if (s_prev->next == NULL)
            end = s_prev;
    }
    end_node = *head;
    while (end_node)
    {
        if (end_node->end)
            break ;
        end_node = end_node->next;
    }
    current = *head;
    e_prev = NULL;
    while (current)
    {
        if (current->next && current->next == end_node)
        {
            e_prev = current;
            break ;
        }
        current = current->next;
    }
    if (end_node != end)
    {
        e_prev->next = end_node->next;
        end->next = end_node;
        end_node->next = NULL;
    }
}