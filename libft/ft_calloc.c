/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 22:26:52 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:31:50 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	max_size;
	size_t	total_size;
	void	*ptr;

	max_size = (size_t)-1;
	if (nmemb != 0 && size > max_size / nmemb)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (total_size > 0)
	{
		total_size--;
		((unsigned char *)ptr)[total_size] = 0;
	}
	return (ptr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	size_t nmemb;
// 	size_t size;

// 	// 1. Caso Normal: ¿Ambas devuelven un puntero válido?
// 	nmemb = 5;
// 	size = sizeof(int);
// 	printf("Normal   -> ft: %p | original: %p\n", 
// 	    	ft_calloc(nmemb, size), calloc(nmemb, size));

// 	// 2. Caso Cero: ¿Cómo reaccionan ante un tamaño de 0?
// 	nmemb = 0;
// 	size = 10;
// 	printf("Con 0    -> ft: %p | original: %p\n", 
// 		    ft_calloc(nmemb, size), calloc(nmemb, size));

// 	// 3. Caso Overflow: ¿Detectan el desbordamiento?
// 	nmemb = (size_t)-1 / 2;
// 	size = 4;
// 	printf("Overflow -> ft: %p | original: %p\n", 
// 		    ft_calloc(nmemb, size), calloc(nmemb, size));

// 	return (0);
// }
