/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:39:11 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/09 12:42:25 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_blank_zero(int width, int zero)
{
	int i;

	i = 0;
	while (++i < width)
	{
		if (zero == 1)
			g_result += ft_putchar_fd('0');
		else
			g_result += ft_putchar_fd(' ');
	}
}

void	put_char(int c)
{
	if (g_option.minus == 1)
		g_result += ft_putchar_fd(c);
	put_blank_zero(g_option.width, g_option.zero);
	if (g_option.minus == 0)
		g_result += ft_putchar_fd(c);
}
