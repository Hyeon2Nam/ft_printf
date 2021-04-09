/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:17:43 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/09 14:23:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(void)
{
	g_option.minus = 0;
	g_option.zero = 0;
	g_option.width = 0;
	g_option.pre = -1;
	g_option.base = 10;
	g_option.type = 0;
	g_option.neg_num = 0;
}

int		ft_len(unsigned long long value)
{
	int	res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= g_option.base;
		res++;
	}
	return (res);
}

char	*ft_change_base(unsigned long long n, char cl)
{
	int		r;
	int		len;
	int		i;
	char	*new_num;

	len = ft_len(n);
	new_num = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_num)
		return (NULL);
	if (n == 0)
		new_num = ft_zero();
	i = 1;
	while (n > 0)
	{
		r = n % g_option.base;
		n /= g_option.base;
		if (r < 10)
			new_num[len - i] = r + '0';
		else
			new_num[len - i] = r - 10 + cl;
		i++;
	}
	new_num[len] = 0;
	return (new_num);
}

void	put_left_width(char *n, int len)
{
	int	minus;
	int	width;

	minus = 0;
	if (g_option.neg_num)
	{
		ft_putchar_fd('-');
		g_result++;
		minus = 1;
	}
	width = g_option.width - len + 1;
	g_result += ft_putstr_fd(n);
	put_blank_zero(width - minus, g_option.zero);
}

void	put_right_width(char *n, int len)
{
	g_option.width -= len;
	if (g_option.neg_num)
	{
		if (!g_option.zero)
			put_blank_zero(g_option.width, 0);
		ft_putchar_fd('-');
		if (g_option.zero)
			put_blank_zero(g_option.width, 1);
		g_result++;
	}
	else
		put_blank_zero(g_option.width + 1, g_option.zero);
	g_result += ft_putstr_fd(n);
}
