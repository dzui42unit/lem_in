#include "lem_in.h"

t_room    *ft_append_element(t_room *head, t_lem *lem, char *data)
{
    t_room  *conductor;
    t_room  *new_node;

    conductor = head;
    while (conductor->next)
        conductor = conductor->next;
    new_node = ft_create_room(lem, data);
    conductor->next = new_node;
    return (new_node);
}

int     ft_list_size(t_room *head)
{
    t_room *current;
    int     size;

    size = 0;
    current = head;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

int     ft_find_list_element(t_room *head, char *key)
{
    t_room  *start;
    int     i;

    i = 0;
    start = head;
    while (start)
    {
        if (ft_strequ(start->name, key))
            return (i);
        start = start->next;
        i++;
    }
    return (-1);
}


void    ft_swap_nodes_rooms(t_room *node_1, t_room *node_2)
{
    t_room  *temp;

    temp = (t_room *)malloc(sizeof(t_room));
    temp->x = node_1->x;
    temp->y = node_1->y;
    temp->start = node_1->start;
    temp->end = node_1->end;
    temp->name = node_1->name;
    node_1->name = node_2->name;
    node_1->x = node_2->x;
    node_1->y = node_2->y;
    node_1->start = node_2->start;
    node_1->end = node_2->end;
    node_2->name = temp->name;
    node_2->x = temp->x;
    node_2->y = temp->y;
    node_2->start = temp->start;
    node_2->end = temp->end;
    free(temp);
}

void    ft_sort_rooms(t_room *head)
{
    t_room *current;
    t_room *start;
    t_room *min;

    if (head->next)
        start= head->next;
    else
        return ;
    while (start)
    {
        min = start;
        current = min;
        while (current->next)
        {
            if (ft_string_compare(min->name, current->name))
                min = current;
            current = current->next;
        }
        if (min != start)
            ft_swap_nodes_rooms(start, min);
        start = start->next;
    }
}

void    ft_sort_path(t_path *head)
{
   t_path *current;
   t_path *start;
   t_path *min;

   if (head)
       start = head;
   else
       return ;
   while (start)
   {
       min = start;
       current = min->next;
       while (current)
       {
           if (min->length > current->length)
           {
               min = current;
           }
           current = current->next;
       }
       if (min != start)
           ft_swap_nodes_path(start, min);
       start = start->next;
   }
}

void    ft_swap_nodes_path(t_path *node_1, t_path *node_2)
{
   t_path  *temp;

   temp = (t_path *)malloc(sizeof(t_path));
   temp->length = node_1->length;
   temp->path = node_1->path;
   node_1->length = node_2->length;
   node_1->path = node_2->path;
   node_2->length = temp->length;
   node_2->path = temp->path;
   temp->path = NULL;	
   free(temp);
}

t_room    *ft_create_room(t_lem *lem, char *data)
{
    t_room  *node;
    char    **splitted;

    node = (t_room *)malloc(sizeof(t_room));
    if (node == NULL)
        ft_error();
    if (ft_count_char(data, ' ') != 2)
        ft_error();
    splitted = ft_strsplit(data, ' ');
    if (splitted[0][0] && splitted[0][0] != 'L' && splitted[0][0] != '#')
        node->name = ft_strdup(splitted[0]);
    else
        ft_error();
    if (ft_check_number(splitted[1]))
        node->x = ft_atoi_unsigned(splitted[1]);
    else
        ft_error();
    if (ft_check_number(splitted[2]))
        node->y = ft_atoi_unsigned(splitted[2]);
    else
        ft_error();
    node->next = NULL;
    if (lem->start == 1)
    {
        node->start = 1;
        node->end = 0;
        lem->start = 0;
    }
    else if (lem->end == 1)
    {
        node->start = 0;
        node->end = 1;
        lem->end = 0;
    }
    else
    {
        node->start = 0;
        node->end = 0;
    }
    return (node);
}

//t_path  *ft_create_path(t_lem *lem)
//{
//    t_path  *node;
//    int     i;
//    int     len;
//
//    node = (t_path *)malloc(sizeof(t_path));
//    if (node == NULL)
//        ft_error();
//    node->path = (int *)malloc(sizeof(int) * lem->size);
//    i = 0;
//    len = 0;
//    while (i < lem->size)
//    {
//        if (lem->temp_path[i] != -1)
//            len++;
//        node->path[i] = lem->temp_path[i];
//        i++;
//    }
//    node->length = len;
//    node->next = NULL;
//    return (node);
//}

//void    ft_append_path(t_path **head, t_lem *lem)
//{
//    t_path  *conductor;
//    t_path  *new_node;
//
//    conductor = *head;
//    while (conductor->next)
//        conductor = conductor->next;
//    new_node = ft_create_path(lem);
//    conductor->next = new_node;
//}