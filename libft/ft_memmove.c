/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:31:00 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/13 22:12:31 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (*d > *s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	{
// 		char	str1[] = "AAAA";
// 		char	str2[] = "BBBB";
// 		char	*dest;

// 		size_t n = 2;
// 		dest = ft_memmove(str2, str1, n);
// 		printf("Caso ft_memmove: %s\n", dest);
// 	}
// 	{
// 		char	str1[] = "AAAA";
// 		char	str2[] = "BBBB";
// 		char	*dest;

// 		size_t n = 2;
// 		dest = memmove(str2, str1, n);
// 		printf("Caso memmove: %s\n", dest);
// 	}
// 	return (0);
// }

/* Overload */
// char str[] = "abcdef";
// char str1[] = "abcdef";

// ft_memmove(str + 2, str, 4);
// memmove(str1 + 2, str1, 4);

// printf("%s\n", str);
// printf("%s\n", str1);
