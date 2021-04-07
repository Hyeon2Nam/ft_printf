/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:49:10 by hyenam            #+#    #+#             */
/*   Updated: 2021/04/07 15:36:19 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define TYPES		"diuxXcsp"
# define OPTIONS	"-0.*123456789"

typedef struct	s_option
{
	int		minus;
	int		zero;
	int		width;
	int		pre;
	int		base;
	char	type;
	int		neg_num;
}				t_option;

extern int		g_result;
extern t_option	g_option;

int				ft_printf(const char *str, ...);
void			do_printf(char *str, va_list ap);
void			set_option(char *str, int i, va_list ap);
void			set_pre_width(char *str, int i, va_list ap);
void			print_str(va_list ap);

void			put_char(int c);
void			put_blank_zero(int width, int zero);

void			put_str(char *str);
void			put_blank_str(char *s);

void			put_nbr(unsigned long long n);
void			ft_pointer_address(char **num);
char			*set_pre(char *n, int len);
void			set_width(char *n, int len);
void			put_right_width(char *n, int len);
void			put_left_width(char *n, int len);
void			ft_change_base(unsigned long long n, char c, char **num);
char			*ft_zero();
int				ft_len(unsigned long long value);

void			init_option();
int				ft_len(unsigned long long value);
void			ft_change_base(unsigned long long n, char c, char **num);

#endif
