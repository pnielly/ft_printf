/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_packing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:21:41 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 16:24:36 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_result_s(t_list *dcp, int taille)
{
	if (dcp->flags[7] == '1' || dcp->flags[7] == '2')
		write(1, dcp->resultw, taille);
	else
		write(1, dcp->result, taille);
	return ;
}

int		ft_result(t_list *dcp, va_list *ap)
{
	if (dcp->flags[7] == '1' || dcp->flags[7] == '2')
		dcp->resultw = va_arg(*ap, wchar_t*);
	else
		dcp->result = va_arg(*ap, char*);
	if (!dcp->result)
		dcp->result = "(null)";
	if ((int)ft_strlen(dcp->result) > dcp->precision && dcp->precision >= 0)
		return (dcp->precision);
	else
		return ((int)ft_strlen(dcp->result));
}

int		ft_display_s(t_list *dcp, va_list *ap)
{
	int	taille;

	taille = ft_result(dcp, ap);
	dcp->width = max(dcp->width, taille);
	dcp->w = dcp->width - taille + 1;
	if (dcp->flags[3] == '1')
	{
		ft_print_result_s(dcp, taille);
		while (--dcp->w > 0)
			write(1, " ", 1);
	}
	else
	{
		while (--dcp->w > 0)
		{
			if (dcp->no_flag == 1)
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
		ft_print_result_s(dcp, taille);
	}
	ft_clean(dcp);
	return (dcp->width);
}
