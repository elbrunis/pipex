/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:48:19 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:13:03 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int num)
{
	const char	hex[16] = "0123456789abcdef";
	int			count;

	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16);
	ft_putchar_fd(hex[num % 16], 1);
	return (count + 1);
}
