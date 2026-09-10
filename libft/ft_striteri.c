/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 21:42:47 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:22:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// // 1. Nuestra f avanza un carácter en el abecedario
// void	advance_letter(unsigned int i, char *c)
// {
// 	(void)i; // Silenciamos 'i'
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c + 1;
// }

// int	main(void)
// {
// 	// Test 1: Caso normal
// 	char str[] = "hola";

// 	ft_striteri(str, advance_letter);
// 	printf("Test 1 (Normal) -> Esperado: ipmb | Obtenido: %s\n", str);

// 	// Test 2: Control contra NULL
// 	ft_striteri(NULL, advance_letter);
// 	ft_striteri(str, NULL);
// 	printf("Test 2 (Protecciones NULL) -> Pasado con éxito (no explotó)\n");

// 	return (0);
// }
