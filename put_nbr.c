/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:46:09 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/08 16:39:56 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(void)
{
	char	*num;
	int		i;

	if (g_option.zero && g_option.pre < 0 && g_option.width > 0)
		g_option.pre = g_option.width;
	if (g_option.pre < 0)
		g_option.pre = 1;
	num = (char *)malloc(sizeof(char) * (g_option.pre + 1));
	num[g_option.pre] = 0;
	i = 0;
	while (i < g_option.pre)
		num[i++] = '0';
	return (num);
}

void	set_width(char *n, int len)
{
	if (g_option.minus)
		put_left_width(n, len);
	else
		put_right_width(n, len);
}

char	*set_pre(char *n, int len)
{
	char	*new_num;
	int		i;
	int		j;

	if (g_option.pre > len)
	{
		new_num = (char *)malloc(sizeof(char) * (g_option.pre + 1));
		if (!new_num)
			return (NULL);
		i = 0;
		while (len + i < g_option.pre)
			new_num[i++] = '0';
		j = 0;
		while (j < len)
			new_num[i++] = n[j++];
		new_num[g_option.pre] = 0;
		return (new_num);
	}
	else
		return (n);
}

void	ft_pointer_address(char **num)
{
	int len;

	*num = ft_strjoin("0x", *num);
	len = ft_strlen(*num);
	set_width(*num, len);
}

void	put_nbr(unsigned long long n)
{
	int		len;
	int		cl;
	char	*num;

	cl = 'a';
	if (g_option.type == 'x' || g_option.type == 'X' || g_option.type == 'p')
		g_option.base = 16;
	if ((g_option.type == 'i' || g_option.type == 'd') && (int)n < 0)
	{
		g_option.neg_num = 1;
		n *= -1;
	}
	if (g_option.type == 'X')
		cl = 'A';
	num = ft_change_base(n, cl);
	num = set_pre(num, ft_strlen(num));
	if (g_option.type == 'p')
		ft_pointer_address(&num);
	else
	{
		len = ft_strlen(num);
		set_width(num, len);
	}
	free(num);
	num = NULL;
}
