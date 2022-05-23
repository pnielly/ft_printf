/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_packing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:56:55 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/01 19:31:58 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*(*g_type_fcts[6]) (t_list *dcp, va_list *ap) = {
	ft_di, ft_di, ft_u, ft_x, ft_capx, ft_p};

void		ft_hexacase(t_list *dcp)
{
	if (dcp->spec == 'p' || (dcp->spec == 'x'
				&& dcp->flags[1] == '1' && ft_atoi(dcp->result)))
	{
		write(1, "0x", 2);
		dcp->printed += 2;
	}
	else if (dcp->spec == 'X' && (dcp->flags[1] == '1' && ft_atoi(dcp->result)))
	{
		write(1, "0X", 2);
		dcp->printed += 2;
	}
	return ;
}

void		ft_print_result_int(t_list *dcp)
{
	ft_hexacase(dcp);
	if (dcp->result[0] == '-')
	{
		write(1, "-", 1);
		dcp->result++;
		dcp->p++;
		dcp->printed++;
	}
	while (--dcp->p > 0)
	{
		write(1, "0", 1);
		dcp->printed++;
	}
	write(1, dcp->result, (int)ft_strlen(dcp->result));
	dcp->printed += (int)ft_strlen(dcp->result);
	return ;
}

int			ft_display_int(t_list *dcp, int pad, int done, char padding)
{
	if (dcp->result[0] == '-' && padding == '0')
	{
		write(1, "-", 1);
		dcp->result++;
		dcp->p++;
		dcp->printed++;
	}
	if (dcp->result[0] == '-' && padding == ' ' && dcp->p > 0)
		dcp->width--;
	if (pad)
		ft_print_result_int(dcp);
	else
		while (--dcp->width > 0)
		{
			write(1, &padding, 1);
			dcp->printed++;
		}
	if (++done < 2 && pad == 1)
		ft_display_int(dcp, 0, 1, padding);
	else if (done < 2 && !pad)
		ft_display_int(dcp, 1, 1, padding);
	if (done == 2)
		return (0);
	ft_clean(dcp);
	return (dcp->printed);
}

int			ft_bonus(t_list *dcp)
{
	if ((dcp->flags[2] == '1' || dcp->flags[0] == '1') && dcp->result[0] != '-'
			&& !ft_strchr("xXp", dcp->spec))
	{
		if (dcp->flags[2] == '1')
			write(1, "+", 1);
		else
			write(1, " ", 1);
		dcp->printed++;
		dcp->width--;
	}
	if (dcp->flags[3] == '1')
		return (ft_display_int(dcp, 1, 0, ' '));
	if (dcp->no_flag == 1 || (dcp->flags[4] == '1' && dcp->precision >= 0))
		return (ft_display_int(dcp, 0, 0, ' '));
	else
		return (ft_display_int(dcp, 0, 0, '0'));
}

int			ft_pack_int(t_list *dcp, va_list *ap)
{
	int		i;
	char	*tab_sp;

	tab_sp = "\144\151\165\170\130\160";
	i = -1;
	while (++i < 6)
		if (dcp->spec == tab_sp[i])
			dcp->result = g_type_fcts[i](dcp, ap);
	i = (int)ft_strlen(dcp->result);
	dcp->p = dcp->precision - i + 1;
	if (dcp->p > 0)
		dcp->width = dcp->width - i - dcp->p + 2;
	else
		dcp->width = dcp->width - i + 1;
	dcp->printed = 0;
	if ((ft_strchr("xX", dcp->spec) && dcp->flags[1] == '1')
			|| dcp->spec == 'p')
		dcp->width -= 2;
	return (ft_bonus(dcp));
}
