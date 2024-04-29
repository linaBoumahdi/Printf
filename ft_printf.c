/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:04:23 by lboumahd          #+#    #+#             */
/*   Updated: 2024/04/29 17:22:28 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar (va_arg(ap, int));
	else if (c == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		len = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'p')
		len = ft_putstr("0x")
			+ ft_putnbr_base (va_arg(ap, unsigned long int), "0123456789abcdef");
	else if (c == 'x')
		len = ft_putnbr_base (va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnbr_base (va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%') 
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		count;

	va_start(argv, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += convert(*s, argv);
			s++;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(argv);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	char *x = NULL; 
// 	char *y = NULL;
// 	int count;
// 	int count1;
// 	// count = printf ("%s\n", x);
// 	// count1 = ft_printf("%s\n", y);
// 	// printf("O : %d \n", count);
// 	// ft_printf("F : %d", count1);
// 	printf(" NULL %s NULL \n ", NULL);
// 	ft_printf(" NULL %s NULL \n", NULL);
// 	return 0;
//  }
#include <stdio.h>
#include <limits.h>
	void	test_simple(void)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: simple string -----------\n\n");
	printf("Testing: (\"\\tHello!\\n\")\n");
	x += printf("  Or\t:\tHello!\n");
	y += ft_printf("  Ft\t:\tHello!\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_percent(void)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: percent -----------\n\n");
	printf("Testing: (\"\\t%%%%\\n\")\n");
	x += printf("  Or\t:\t%%\n");
	y += ft_printf("  Ft\t:\t%%\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

}

void	test_c(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%c -----------\n\n");
	printf("Testing: (\"\\t%%c\\n\", 'a')\n");
	x += printf("  Or\t:\t%c\n", 'a');
	y += ft_printf("  Ft\t:\t%c\n", 'a');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe character %%c is visible.\\n\", 'x')\n");
	x += printf("  Or\t:\tThe character %c is visible.\n", 'x');
	y += ft_printf("  Ft\t:\tThe character %c is visible.\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_s(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%s -----------\n\n");
	printf("Testing: (\"\\t%%s\\n\", \"coucou, ca va?\")\n");
	x += printf("  Or\t:\t%s\n", "coucou, ca va?");
	y += ft_printf("  Ft\t:\t%s\n", "coucou, ca va?");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe string \\\"%%s\\\" is visible.\\n\", \"TRALALA\")\n");
	x += printf("  Or\t:\tThe string \"%s\" is visible.\n", "TRALALA");
	y += ft_printf("  Ft\t:\tThe string \"%s\" is visible.\n", "TRALALA");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	char *s = NULL;
	if (s == NULL)
		write(1, "(null)\n", 7);
	printf("Testing: (\"\\tNULL %%s NULL.\\n\", NULL)\n");
	x += printf("  Or\t:\tNULL %s NULL.\n", s);
	y += ft_printf("  Ft\t:\tNULL %s NULL.\n", s);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_d(void)
{
	int x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%d -----------\n\n");
	printf("Testing: (\"\\t%%d\\n\", 42)\n");
	x += printf("  Or\t:\t%d\n", 42);
	y += ft_printf("  Ft\t:\t%d\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe number %%d is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe number %d is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe number %d is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%d\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%d\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%d\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%d\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%d\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%d\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MIN - INT_MIN)\n");
	x += printf("  Or\t:\t%i\n", INT_MIN - INT_MIN);
	y += ft_printf("  Ft\t:\t%i\n", INT_MIN - INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_i(void)
{
	int x, y;
	printf("\n----------- TEST: %%i -----------\n\n");
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", 4422)\n");
	x += printf("  Or\t:\t%i\n", 4422);
	y += ft_printf("  Ft\t:\t%i\n", 4422);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe number %%i is visible.\\n\", 0)\n");
	x += printf("  Or\t:\tThe number %i is visible.\n", 0);
	y += ft_printf("  Ft\t:\tThe number %i is visible.\n", 0);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%i\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%i\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%i\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%i\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MIN + INT_MAX)\n");
	x += printf("  Or\t:\t%i\n", INT_MIN + INT_MAX);
	y += ft_printf("  Ft\t:\t%i\n", INT_MIN + INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_x(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%x -----------\n\n");
	printf("Testing: (\"\\t%%x\\n\", 42)\n");
	x += printf("  Or\t:\t%x\n", 42);
	y += ft_printf("  Ft\t:\t%x\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe hex number %%x is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe hex number %x is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe hex number %x is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%x\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%x\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%x\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%x\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", -42)\n");
	x += printf("  Or\t:\t%x\n", -42);
	y += ft_printf("  Ft\t:\t%x\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%x\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%x\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_X(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%X -----------\n\n");
	printf("Testing: (\"\\t%%X\\n\", 42)\n");
	x += printf("  Or\t:\t%X\n", 42);
	y += ft_printf("  Ft\t:\t%X\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe hex number %%X is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe hex number %X is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe hex number %X is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%X\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%X\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%X\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%X\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", -42)\n");
	x += printf("  Or\t:\t%X\n", -42);
	y += ft_printf("  Ft\t:\t%X\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%X\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%X\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_u(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%u -----------\n\n");
	printf("Testing: (\"\\t%%u\\n\", 42)\n");
	x += printf("  Or\t:\t%u\n", 42);
	y += ft_printf("  Ft\t:\t%u\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\tThe number %%u is visible.\\n\", 5671)\n");
	x += printf("  Or\t:\tThe number %u is visible.\n", 5671);
	y += ft_printf("  Ft\t:\tThe number %u is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", INT_MAX)\n");
	x += printf("  Or\t:\t%u\n", INT_MAX);
	y += ft_printf("  Ft\t:\t%u\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", INT_MIN)\n");
	x += printf("  Or\t:\t%u\n", INT_MIN);
	y += ft_printf("  Ft\t:\t%u\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", -42)\n");
	x += printf("  Or\t:\t%u\n", -42);
	y += ft_printf("  Ft\t:\t%u\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", UINT_MAX)\n");
	x += printf("  Or\t:\t%u\n", UINT_MAX);
	y += ft_printf("  Ft\t:\t%u\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_p(void)
{
	int	x, y;
	printf("\n----------- TEST: %%p -----------\n\n");
	x = 0;
	y = 0;
	int	n;
	char	c;
	void	*p;

	n = 50;
	c = 'a';
	p = NULL;
	printf("Testing: (\"\\t%%p\\n\", (void *)&n)\n");
	x += printf("  Or\t:\t%p\n", (void *)&n);
	y += ft_printf("  Ft\t:\t%p\n", (void *)&n);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", (void *)&c)\n");
	x += printf("  Or\t:\t%p\n", (void *)&c);
	y += ft_printf("  Ft\t:\t%p\n", (void *)&c);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", p)\n");
	x += printf("  Or\t:\t%p\n", p);
	y += ft_printf("  Ft\t:\t%p\n", p);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_all(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\n----------- TEST: ALL -----------\n\n");
	printf("Testing: (\"\\tThe int is %%i or %%d, the char is %%c, the string is \\\"%%s\\\", the hex is %%x or %%X, the unsigned is %%u and the percent is %%%%.\\n\", 42, -42, 's', \"Hello\", 42, 42, 242)\n");
	x += printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	y += ft_printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int main()
{
    test_simple();
    test_c();
    test_d();
    test_i();
    test_p();
    test_percent();
    test_s();
    test_u();
    test_X();
    test_x();
	printf("  Or\t:\t%%, %i, %c, %s\n", 50, 'a', NULL);
	printf("  Ft\t:\t%%, %i, %c, %s\n", 50, 'a', NULL);
}
