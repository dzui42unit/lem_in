#include "lem_in.h"

void	ft_move_lem(t_lem *lem, t_path *path, t_room *head_room)
{
	int 	i;
	int 	j;
	int  	place;
	t_path 	*start;

	i = 0;
	lem->lems = (int **)malloc(sizeof(int *) * lem->ants);
	while (i < lem->ants)
	{
		lem->lems[i] = (int *)malloc(sizeof(int) * 2);
		lem->lems[i][0] = 1;
		lem->lems[i][1] = 0;
		i++;
	}
	j = lem->ants;
	while (lem->ants > 0)
	{
		i = 0;
		while (i < j)
		{
			if (lem->lems[i][0] == 1)
			{
				start = path;
				while (start)
				{
					place = ft_find_room(lem, start, i);
					if (ft_is_free_room(lem, place))
					{
						lem->lems[i][1] = place;
						if (place == lem->size - 1)
						{
							lem->lems[i][0] = 0;
							lem->lems[i][0] = -1;
							lem->ants--;
						}
						ft_printf("L%d-", i + 1);
						ft_print_needed_node(lem,head_room, place);
						break ;
					}
					start = start->next;
				}
			}
			i++;
		}
		ft_printf("\n");
	}
}

int 	ft_is_free_room(t_lem *lem, int nb_room)
{
	int i;

	i = 0;
	while (i < lem->ants)
	{
		if (lem->lems[i][1] == nb_room)
			return (0);
		i++;
	}
	return (1);
}

int 	ft_find_room(t_lem *lem, t_path *way, int active_lem)
{
	int i;

	i = lem->lems[active_lem][1] + 1;
	while (i < lem->size)
	{
		if (way->path[i] == 1)
			return (i);
		i++;
	}
	return (-1);
}
