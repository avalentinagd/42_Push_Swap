/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 04:03:15 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 21:33:02 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*s2;

	len = 0;
	while (s[len])
		len++;
	s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str_ft;
// 	char	*str_original;

// 	// Caso 1: String normal estándar
// 	str_ft = ft_strdup("Hola 42!");
// 	str_original = strdup("Hola 42!");
// 	printf("Normal -> ft: %s (%p) | original: %s (%p)\n", 
// 		str_ft, str_ft, str_original, str_original);
// 	// free(str_ft);
// 	// free(str_original);

// 	// Caso 2: String vacío (buen manejo del \0)
// 	str_ft = ft_strdup("");
// 	str_original = strdup("");
// 	printf("Vacío  -> ft: \"%s\" (%p) | original: \"%s\" (%p)\n", 
// 		str_ft, str_ft, str_original, str_original);
// 	// free(str_ft);
// 	// free(str_original);

// 	return (0);
// }
