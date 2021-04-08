#include <stdio.h>

int ft_printf(const char *str, ...);

int main()
{
    int a = -5;
    // int b = 3;
    int f = -8;

    printf("1. %0.*d\n", a, f);
    ft_printf("2. %0.*d\n", f);
}

//gcc -Wall -Wextra -Werror main.c put_*c ft_printf.c printf_util.c -L../libft -lft