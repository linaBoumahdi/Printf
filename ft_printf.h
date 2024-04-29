/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:55:19 by lboumahd          #+#    #+#             */
/*   Updated: 2024/04/29 15:55:39 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned long i, char *base);
int	ft_putnbr(long i);

#endif