/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:31:59 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:13:19 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hex(unsigned long num)
{
	const char	hex[16] = "0123456789abcdef";

	if (num >= 16)
	{
		put_hex(num / 16);
	}
	ft_putchar_fd(hex[num % 16], 1);
}

static int	count_hex(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	num;
	int				count;

	num = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_put_str("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	if (num == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		put_hex(num);
		count += count_hex(num);
	}
	return (count);
}
