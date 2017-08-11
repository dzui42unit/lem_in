/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:17:02 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:17:03 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_handle_errors(t_lem *lem, char *buff)
{
	if (ft_count_char(buff, '-') > 1 || buff[0] == '-')
		ft_error();
	if (ft_strequ(buff, "") || lem->start_counter > 1 || lem->end_counter > 1)
		ft_error();
}

void	ft_error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
