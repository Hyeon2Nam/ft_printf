/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:49:41 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/09 17:42:59 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_result;
t_option	g_option;

void	print_ap(va_list ap)
{
	if ((g_option.zero == 1 && g_option.minus == 1) ||
		(g_option.type != '%' && g_option.pre >= 0))
		g_option.zero = 0;
	if (g_option.type == 'c')
		put_char(va_arg(ap, int));
	else if (g_option.type == 's')
		put_str(va_arg(ap, char *));
	else if (g_option.type == '%')
		put_char('%');
	else if (g_option.type == 'd' || g_option.type == 'i')
		put_nbr(va_arg(ap, int));
	else if (g_option.type == 'u' || g_option.type == 'x'
		|| g_option.type == 'X')
		put_nbr(va_arg(ap, unsigned int));
	else if (g_option.type == 'p')
		put_nbr(va_arg(ap, unsigned long long));
}

void	set_pre_width(char *str, int i, va_list ap)
{
	if (ft_isdigit(str[i]))
	{
		if (g_option.pre == -1)
			g_option.width = g_option.width * 10 + str[i] - '0';
		else
			g_option.pre = g_option.pre * 10 + str[i] - '0';
	}
	else
	{
		if (g_option.pre == -1)
		{
			g_option.width = va_arg(ap, int);
			if (g_option.width < 0)
			{
				g_option.minus = 1;
				g_option.width *= -1;
			}
		}
		else
			g_option.pre = va_arg(ap, int);
	}
}

void	set_option(char *str, int i, va_list ap)
{
	if (str[i] == '-')
		g_option.minus = 1;
	if (str[i] == '0' && g_option.pre != 0)
		g_option.zero = 1;
	if (str[i] == '.')
		g_option.pre = 0;
	if (ft_isdigit(str[i]) || str[i] == '*')
		set_pre_width(str, i, ap);
}

void	do_printf(char *str, va_list ap)
{
	int i;

	i = -1;
	while (str[++i])
	{
		init_option();
		if (str[i] == '%')
		{
			while (str[++i] && (ft_strchr(OPTIONS, str[i]) ||
				ft_strchr(TYPES, str[i]) || str[i] == '%'))
			{
				if (ft_strchr(OPTIONS, str[i]))
					set_option(str, i, ap);
				else
				{
					g_option.type = str[i];
					break ;
				}
			}
			print_ap(ap);
		}
		else
			g_result += ft_putchar_fd(str[i]);
	}
}

int		ft_printf(const char *str, ...)
{
	va_list ap;

	g_result = 0;
	va_start(ap, str);
	do_printf((char *)str, ap);
	va_end(ap);
	return (g_result);
}
