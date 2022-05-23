/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:06:51 by pnielly           #+#    #+#             */
/*   Updated: 2019/12/14 18:06:35 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wctype.h>

typedef struct		s_list
{
	int							no_flag;
	char						*flags;
	int							width;
	int							precision;
	int							w;
	int							p;
	int							pad;
	int							sfpr;
	int							spec;
	wint_t						*specw;
	char						*result;
	wchar_t						*resultw;
	int							printed;
	int							a;
	signed char					b;
	long long int				c;
	short int					d;
	long int					e;
	unsigned int				f;
	unsigned char				g;
	unsigned long long int		h;
	unsigned short int			i;
	unsigned long int			j;
}					t_list;

char				*ft_di(t_list *dcp, va_list *ap);
char				*ft_u(t_list *dcp, va_list *ap);
char				*ft_x(t_list *dcp, va_list *ap);
char				*ft_capx(t_list *dcp, va_list *ap);
char				*ft_p(t_list *dcp, va_list *ap);

void				ft_clean(t_list *dcp);
int					ft_sign(long nb);
int					max(int i, int j);
int					max_di(t_list *dcp);
int					min_di(t_list *dcp);
int					max_else(t_list *dcp);
int					min_else(t_list *dcp);
int					ft_display_s(t_list *dcp, va_list *ap);
int					ft_precision(t_list *dcp, int p, int w, char padding);
int					ft_width(t_list *dcp, int p, int w, char padding);
int					ft_packing(t_list *dcp, va_list *ap);
int					ft_pack_int(t_list *dcp, va_list *ap);
int					ft_pack_s(t_list *dcp, va_list *ap);
int					ft_n(t_list *dcp, va_list *ap);
void				ft_flag(char *str, t_list *dcp);
char				*ft_convertbase(long long nb, int base,
				int size, int precision);
char				*ft_convertbase_u(unsigned int nb, int base,
				int size, int precision);
char				*ft_conversion(t_list *dcp, va_list *ap);
int					ft_decompose(char *str, int strlength,
				va_list *ap, int sfpr);
int					ft_printf(const char *fmt, ...);
void				ft_putchar(const char c);
void				ft_putstr_until(const char *str, char c);
void				ft_putstr(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrchr(const char *s, int c, int stop);
char				*ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst,
						const char *src, size_t dstsize);
void				*ft_memcpy(void *dst,
						const void *src, size_t n);
char				*ft_itoa(int n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isdigit(char c);
void				*ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);

#endif
