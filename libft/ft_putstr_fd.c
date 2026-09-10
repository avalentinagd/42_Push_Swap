/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:50:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:20:14 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len_s;

	if (!s)
		return ;
	len_s = ft_strlen(s);
	write(fd, s, len_s);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd_file;

// 	// Test 1: Imprimir un string entero en la pantalla normal (fd 1)
// 	ft_putstr_fd("Hola desde el canal 1 (STDOUT)\n", 1);

// 	// Test 2: Imprimir en un archivo real (fd 3+)
// 	fd_file = open("test_str.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd_file >= 0)
// 	{
// 		ft_putstr_fd("Este texto se ha guardado dentro del archivo.", fd_file);
// 		close(fd_file);
// 		printf("Test 2 -> Archivo 'test_str.txt' creado con exito.\n");
// 	}

// 	// Test 3: Proteccion contra NULL (No debe explotar)
// 	ft_putstr_fd(NULL, 1);
// 	printf("Test 3 -> Proteccion NULL verificada (no exploto).\n");

// 	return (0);
// }
