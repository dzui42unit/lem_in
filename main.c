/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:28:31 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 20:28:33 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_initial_reading(t_lem *lem, char *buff)
{
	lem->start = 0;
	lem->end = 0;
	lem->show_path = 0;
	lem->start_counter = 0;
	lem->end_counter = 0;
	lem->input_data = ft_strnew(1);
	lem->radius = 30;
	lem->visual = 0;
	lem->radius_2 = lem->radius * lem->radius;
	while (get_next_line(0, &buff) && buff[0] == '#')
	{
		if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end")
			|| ft_strequ(buff, "##path") || ft_strequ(buff, "##visual"))
			ft_error();
		ft_join(lem, buff);
		free(buff);
	}
	if (!ft_check_number(buff) || ft_strequ(buff, ""))
		ft_error();
	lem->ants = ft_atoi_unsigned(buff);
	ft_join(lem, buff);
	free(buff);
}

void	ft_process_commands(t_lem *lem, char *buff)
{
	if (ft_strequ(buff, "##start"))
	{
		lem->start_counter++;
		lem->start = lem->start_counter;
	}
	if (ft_strequ(buff, "##end"))
	{
		lem->end_counter++;
		lem->end = lem->end_counter;
	}
	if (ft_strequ(buff, "##path"))
		lem->show_path = 1;
	if (ft_strequ(buff, "##visual"))
		lem->visual = 1;
}

void	ft_finish_search(t_lem *lem, t_path *head_path, t_room *head_room)
{
	ft_sort_path(head_path);
	ft_printf("%s", lem->input_data);
	lem->path = head_path;
	lem->head = head_room;
	lem->flag = 0;
	lem->init = lem->ants;
	ft_search_parallel_paths(lem);
	if (lem->show_path == 1)
		ft_print_path(lem, head_room, head_path);
	ft_assign_lems(lem);
	ft_printf("\n");
	if (lem->visual)
		ft_draw_graph(lem);
	ft_move_lem(lem, head_path, head_room);
	ft_free_rooms(head_room);
	ft_free_path(head_path);
	ft_free_matrix(lem);
	free(lem->lems);
}

void	ft_start_search(t_lem *lem, t_room *head_room, char *buff)
{
	t_path *head_path;

	head_path = NULL;
	if (!ft_check_dupliactes(head_room))
		ft_error();
	if (!ft_check_start_end(head_room))
		ft_error();
	ft_set_start(head_room);
	ft_set_end(head_room);
	ft_set_id(head_room);
	lem->size = ft_list_size(head_room);
	ft_make_matrix(head_room, lem, buff);
	lem->visited[0] = (ft_get_room(head_room, 0))->id;
	lem->index = 1;
	lem->counter = 0;
	ft_depth_first_search(lem, head_room, lem->visited, &head_path);
	if (head_path == NULL)
		ft_error();
	ft_finish_search(lem, head_path, head_room);
}

int		main(void)
{
	t_lem	lem;
	char	*buff;

	buff = NULL;
	lem.head = NULL;
	ft_initial_reading(&lem, buff);
	while (get_next_line(0, &buff))
	{
		if (ft_count_char(buff, '-') == 1 && buff[0] != '-')
			break ;
		ft_handle_errors(&lem, buff);
		if (buff[0] == '#')
			ft_process_commands(&lem, buff);
		else
		{
			if (lem.head == NULL)
				lem.head = ft_create_room(&lem, buff);
			else
				ft_append_element(lem.head, &lem, buff);
		}
		ft_join(&lem, buff);
		free(buff);
	}
	ft_start_search(&lem, lem.head, buff);
	return (0);
}
