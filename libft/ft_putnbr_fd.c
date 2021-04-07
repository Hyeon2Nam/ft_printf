/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:29:16 by riiringim         #+#    #+#             */
/*   Updated: 2021/03/14 09:31:02 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nbr)
{
	long	n;

	n = nbr;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(-n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10);
			ft_putnbr_fd(n % 10);
		}
		else
			ft_putchar_fd(n + '0');
	}
}
