/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:25:59 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/29 20:33:53 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*temp;
	const char	*s;

	temp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		if (temp[i] == (char)c)
			return (dst + i + 1);
		++i;
	}
	return (NULL);
}
