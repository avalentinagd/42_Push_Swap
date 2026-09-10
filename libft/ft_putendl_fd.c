/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:50:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:14:58 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// Prueba con ft_putstr_fd
// 	printf("Con ft_putstr_fd:\n");
// 	ft_putstr_fd("Texto A", 1);
// 	ft_putstr_fd("Texto B", 1);

// 	printf("\n\n");

// 	// Prueba con ft_putendl_fd
// 	printf("Con ft_putendl_fd:\n");
// 	ft_putendl_fd("Texto A", 1);
// 	ft_putendl_fd("Texto B", 1);

// 	return (0);
// }
