/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:46:49 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:12:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h> // Para 'open' y los modos de archivos
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd_archivo;

// 	// Test 1: Enviar a la salida estándar (Pantalla normal)
// 	printf("Test 1 (STDOUT) -> Debe aparecer una 'A': ");
// 	ft_putchar_fd('A', 1);
// 	printf("\n");

// 	// Test 2: Enviar a la salida de errores (Sigue siendo la pantalla)
// 	printf("Test 2 (STDERR) -> Debe aparecer una 'B': ");
// 	ft_putchar_fd('B', 2);
// 	printf("\n");

// 	// Test 3: Enviar a un archivo real en tu disco duro
// 	// Creamos/Abrimos un archivo llamado test.txt con permisos de escritura
// 	fd_archivo = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd_archivo < 0)
// 	{
// 		printf("Error abriendo el archivo de prueba.\n");
// 		return (1);
// 	}

// 	// Escribimos una 'C' dentro del archivo, ¡no saldrá en la terminal!
// 	ft_putchar_fd('C', fd_archivo);
// 	close(fd_archivo);

// 	printf("Test 3 (Archivo) -> Crea 'test.txt' que contiene una 'C'.\n");
// 	return (0);
// }
