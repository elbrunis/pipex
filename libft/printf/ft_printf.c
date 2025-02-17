/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:12:55 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:12:34 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_lttr(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		count += ft_putint(va_arg(args, int));
	if (format == 'u')
		count += ft_putuint(va_arg(args, unsigned int));
	if (format == 'x')
		count += ft_puthex(va_arg(args, unsigned int));
	if (format == 'X')
		count += ft_putm_hex(va_arg(args, unsigned int));
	if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += put_format(args, format[i + 1]);
			i++;
		}
		else
			count += put_lttr(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
