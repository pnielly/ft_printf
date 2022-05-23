/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:44:01 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 15:59:12 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_check_error(char *str)
{
	int	k;
	int	j;

	if (!str)
		return (1);
	if (!str[0])
		return (1);
	k = 1;
	while (ft_strchr("#0 +-'hl", str[k]) && str[k])
		k++;
	while (ft_strchr(".*0123456789", str[k]) && str[k])
		k++;
	if (str[k] == '\0')
		return (1);
	j = 1;
	while (ft_strchr("# +-0hl'", str[j]))
		j++;
	while (j < k)
	{
		if (!ft_strchr("*.0123456789", str[j]))
			return (1);
		j++;
	}
	return (0);
}

int			ft_strlen_arg(const char *str)
{
	int		i;

	i = 1;
	while (ft_strchr("-0# +'hl.*123456789", str[i]) && str[i])
		i++;
	return (i + 1);
}

int			ft_printf(const char *fmt, ...)
{
	va_list ap;
	char	*str;
	int		strlength;
	int		i;

	i = 0;
	va_start(ap, fmt);
	while ((str = ft_strchr(fmt, '%')))
	{
		if (ft_check_error(str))
			return (-1);
		strlength = ft_strlen_arg(str);
		i = i + ft_strlen(fmt) - ft_strlen(ft_strchr(fmt, '%'));
		ft_putstr_until(fmt, '%');
		i = i + ft_decompose(str, strlength, &ap, i);
		fmt = fmt + (ft_strlen(fmt) -
				ft_strlen(ft_strchr(fmt, '%'))) + strlength;
	}
	va_end(ap);
	i = i + ft_strlen(fmt);
	ft_putstr_until(fmt, '\0');
	return (i);
}
