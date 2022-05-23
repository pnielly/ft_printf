/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_packing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:47:00 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/01 17:46:37 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_result_c(t_list *dcp, va_list *ap)
{
	if (dcp->flags[7] == '2')
		dcp->specw = va_arg(*ap, wint_t*);
	else
		dcp->spec = va_arg(*ap, int);
	if (dcp->flags[7] == '1' || dcp->flags[7] == '2')
		write(1, &dcp->specw, 1);
	else
		write(1, &dcp->spec, 1);
	return ;
}

int		ft_display_c(t_list *dcp, va_list *ap)
{
	int	i;

	i = max(dcp->width, 1);
	if (dcp->flags[3] == '1')
	{
		ft_print_result_c(dcp, ap);
		while (--dcp->width > 0)
			write(1, " ", 1);
	}
	else
	{
		while (--dcp->width > 0)
		{
			if (dcp->no_flag == 1)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
		ft_print_result_c(dcp, ap);
	}
	ft_clean(dcp);
	return (i);
}

int		ft_display_else(t_list *dcp)
{
	int	i;

	i = max(dcp->width, 1);
	if (dcp->flags[3] == '1')
	{
		write(1, &dcp->spec, 1);
		while (--dcp->width > 0)
			write(1, " ", 1);
	}
	else
	{
		while (--dcp->width > 0)
		{
			if (dcp->no_flag == 1)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
		write(1, &dcp->spec, 1);
	}
	ft_clean(dcp);
	return (i);
}

int		ft_packing(t_list *dcp, va_list *ap)
{
	if (dcp->width < 0)
	{
		dcp->width = -dcp->width;
		dcp->flags[3] = '1';
	}
	if (ft_strchr("diuxXp", dcp->spec))
		return (ft_pack_int(dcp, ap));
	if (dcp->spec == 'c')
	{
		dcp->width = max(dcp->width, 1);
		return (ft_display_c(dcp, ap));
	}
	if (dcp->spec == 's')
		return (ft_display_s(dcp, ap));
	if (dcp->spec == 'n')
		return (ft_n(dcp, ap));
	else
		return (ft_display_else(dcp));
}
