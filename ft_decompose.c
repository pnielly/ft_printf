/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decompose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:56:06 by pnielly           #+#    #+#             */
/*   Updated: 2020/01/01 19:33:34 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_apply_atoi(char *str, t_list *dcp, int i)
{
	if (str[i - 1] == '.' && ft_isdigit(str[i]))
	{
		dcp->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	else if (str[i - 1] != '.' && ft_isdigit(str[i]))
	{
		dcp->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int			ft_get_wpr(char *str, t_list *dcp, int i, va_list *ap)
{
	dcp->precision = -1;
	dcp->width = 0;
	while (ft_strchr("-.*0123456789", str[i]))
	{
		if (str[i] == '.' && ft_strchr("-.*0123456789", str[i + 1]))
			i++;
		if (str[i] == '.' && !ft_strchr("-.*0123456789", str[i + 1]))
			dcp->precision = 0;
		if (str[i - 1] == '.' && str[i] == '*')
			dcp->precision = va_arg(*ap, int);
		else if (str[i - 1] == '.' && ft_isdigit(str[i]))
			i = ft_apply_atoi(str, dcp, i);
		else if (str[i - 1] != '.' && str[i] == '*')
			dcp->width = va_arg(*ap, int);
		if (dcp->width < 0)
			dcp->flags[3] = '1';
		else if (str[i - 1] != '.' && ft_isdigit(str[i]))
			i = ft_apply_atoi(str, dcp, i);
		i++;
	}
	if (str[i - 1] == '.')
		dcp->precision = 0;
	return (ft_packing(dcp, ap));
}

void		ft_dcp_init(t_list *dcp)
{
	dcp->a = 0;
	dcp->b = 0;
	dcp->c = 0;
	dcp->d = 0;
	dcp->e = 0;
	dcp->f = 0;
	dcp->g = 0;
	dcp->h = 0;
	dcp->i = 0;
	dcp->j = 0;
	return ;
}

int			ft_decompose(char *str, int strlength, va_list *ap, int sfpr)
{
	int		i;
	t_list	*dcp;

	if (!(dcp = malloc(sizeof(t_list))))
		return (0);
	ft_dcp_init(dcp);
	dcp->flags = ft_strdup("\040\043\053\055\060\150\154\110\114");
	ft_flag(str, dcp);
	dcp->sfpr = sfpr;
	dcp->spec = str[strlength - 1];
	i = 1;
	while (ft_strchr("\040\043\053\055\060\150\154\110\114",
				str[i]) && i < strlength)
		i++;
	return (ft_get_wpr(str, dcp, i, ap));
}
