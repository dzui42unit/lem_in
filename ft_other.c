/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:11:47 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:11:48 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_comment(char *str)
{
	int i;

	i = 0;
	while (str[i] == '#')
		i++;
	if (i == 0)
		return (0);
	return (1);
}

int			ft_count_char(char *str, char ch)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == ch)
			nb++;
		i++;
	}
	return (nb);
}

uintmax_t	ft_atoi_unsigned(char *str)
{
	uintmax_t	number;
	uintmax_t	pow;
	int			i;

	i = 0;
	pow = 1;
	number = 0;
	while (str[i])
	{
		pow *= 10;
		i++;
	}
	i = 0;
	pow /= 10;
	while (pow != 0)
	{
		number += (str[i] - '0') * pow;
		pow /= 10;
		i++;
	}
	return (number);
}

void		ft_join(t_lem *lem, char *str2)
{
	char	*res;
	char	*temp;
	int		sum;

	sum = (int)(2 + ft_strlen(lem->input_data) + ft_strlen(str2));
	temp = lem->input_data;
	res = (char *)malloc(sum * sizeof(char));
	ft_strcpy(res, lem->input_data);
	ft_strcat(res, str2);
	ft_strcat(res, "\n");
	free(temp);
	lem->input_data = res;
}
