/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:07:44 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:06:56 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "Hola Mundo";
// 	char	*res;

// 	// CASO 1: Caso normal
// 	res = ft_substr(str, 0, 4);
// 	printf("Caso Normal (0, 4)  -> Esperado: [Hola]   | Resultado: [%s]\n"
//             , res);
// 	free(res);

// 	// CASO 2: Start está fuera de los límites de la cadena
// 	res = ft_substr(str, 20, 5);
// 	printf("Start grande (20, 5)-> Esperado: []      | Resultado: [%s]\n"
//             , res);
// 	free(res);

// 	// CASO 3: Len < el resto de la cadena
// 	res = ft_substr(str, 5, 50);
// 	printf("Len grande (5, 50)  -> Esperado: [Mundo] | Resultado: [%s]\n"
//             , res);
// 	free(res);

// 	return (0);
// }
