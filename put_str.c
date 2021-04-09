/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:02:58 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/09 18:36:43 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_blank_str(char *s)
{
	int len;
	int width;

	len = (int)ft_strlen(s);
	if (g_option.width < len)
		g_option.width = len;
	width = g_option.width - len + 1;
	put_blank_zero(width, g_option.zero);
}

void	put_str(char *str)
{
	char *s;

	if (str == NULL)
		str = "(null)";
	if (g_option.pre < 0)
		g_option.pre = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (g_option.pre + 1));
	if (!s)
		return ;
	ft_strlcpy(s, str, g_option.pre + 1);
	if (g_option.minus == 1)
	{
		g_result += ft_putstr_fd(s);
		put_blank_str(s);
	}
	else
	{
		put_blank_str(s);
		g_result += ft_putstr_fd(s);
	}
	free(s);
	s = NULL;
}
