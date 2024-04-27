/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:53:44 by lboumahd          #+#    #+#             */
/*   Updated: 2024/04/27 20:08:17 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(2, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr_base(long long i, char *base)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		ft_putchar ('-');
		count ++;
	}
	if (i >= ft_strlen (base))
		count += ft_putnbr_base (i / ft_strlen(base), base);
	count += ft_putchar (base [i % ft_strlen(base)]);
	return (count);
}
