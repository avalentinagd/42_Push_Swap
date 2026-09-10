/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:46:49 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/13 22:12:48 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	dest_byte;
	size_t			i;

	dest_str = (unsigned char *)s;
	dest_byte = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest_str[i] = dest_byte;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	buffer[10] = "holA MUNDO";

// 	ft_memset(buffer, 'A', 3);
// 	printf("%s\n", buffer);
// 	return (0);
// }

//void *s: Recibe la dirección de memoria a llenar (no importa el tipo)
//void *: Retorna esa misma dirección para poder encadenar llamadas
//ESTO ULTIMO NO ME QUEDA CLARO, INVESTIGARLO!!!!
