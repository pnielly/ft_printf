/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:26:08 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 17:11:25 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(const char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return ;
}

void	ft_putstr_until(const char *str, char c)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		while (*str != c)
			write(1, (void*)str++, 1);
	else
		ft_putstr(str);
	return ;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + 1;
	if (!(dest = (char*)malloc(sizeof(char) * len)))
		return ((char *)0);
	return ((char *)ft_memcpy(dest, s1, len));
}

void	ft_clean(t_list *dcp)
{
	free(dcp->flags);
	free(dcp);
	return ;
}
