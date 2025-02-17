/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:52:18 by biniesta          #+#    #+#             */
/*   Updated: 2024/10/05 18:44:55 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_trim_char(const char c, const char *trim)
{
	while (*trim)
	{
		if (c == *trim)
			return (1);
		trim++;
	}
	return (0);
}

static size_t	is_start(const char *s1, const char *trim)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_in_trim_char(s1[start], trim))
	{
		start++;
	}
	return (start);
}

static size_t	is_end(const char *s1, const char *trim)
{
	size_t	end;
	size_t	of_start;

	of_start = is_start(s1, trim);
	end = 0;
	while (s1[end])
	{
		end++;
	}
	end--;
	while (end > of_start && is_in_trim_char(s1[end], trim))
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = is_start(s1, set);
	end = is_end(s1, set);
	trim_str = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!trim_str)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		trim_str[i] = s1[start + i];
		i++;
	}
	trim_str[i] = '\0';
	return (trim_str);
}
// int	main(void)
// {
// 	char *result;

// 	result = ft_strtrim("   Hello, World!   ", "rd !l");
// 	printf("Trimmed: '%s'\n", result);
// 	free(result);
// 	return (0);
// }