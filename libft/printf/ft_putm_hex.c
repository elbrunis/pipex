/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putm_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:49:49 by biniesta          #+#    #+#             */
/*   Updated: 2024/12/25 19:13:12 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putm_hex(unsigned int num)
{
	const char	hex[16] = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (num >= 16)
		count = ft_putm_hex(num / 16);
	ft_putchar_fd(hex[num % 16], 1);
	return (count + 1);
}
