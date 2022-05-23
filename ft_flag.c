/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:04:07 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/01 19:32:15 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_length_modifier(char *str, t_list *dcp)
{
	char	*s1;
	char	*s2;

	if (dcp->flags[6] == '1' || dcp->flags[7] == '1')
	{
		s1 = ft_strrchr(str, 'h', dcp->spec);
		s2 = ft_strrchr(str, 'l', dcp->spec);
		if (ft_strlen(s1) < ft_strlen(s2))
		{
			s1 = s1 - 1;
			if (s1[0] == 'h')
				dcp->flags[8] = '2';
			else
				dcp->flags[6] = '2';
		}
		else
		{
			s2 = s2 - 1;
			if (s2[0] == 'l')
				dcp->flags[9] = '2';
			else
				dcp->flags[7] = '2';
		}
	}
	return ;
}

void		ft_flag(char *str, t_list *dcp)
{
	int	i;
	int	j;

	j = 0;
	while (ft_strchr(" #+-0'hl", str[++j]))
	{
		i = -1;
		while (++i < 7)
			if (dcp->flags[i] == str[j])
				dcp->flags[i] = '1';
		if (str[j] == 'h' && str[j - 1] == 'h')
			dcp->flags[8] = '1';
		if (str[j] == 'l' && str[j - 1] == 'l')
			dcp->flags[9] = '1';
	}
	if (dcp->flags[3] != '1' && dcp->flags[4] != '1')
		dcp->no_flag = 1;
	else
		dcp->no_flag = 0;
	if (dcp->flags[2] == '1')
		dcp->flags[0] = '\040';
	ft_length_modifier(str, dcp);
	return ;
}
