/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// void	del_content(void *content)
// {
// 	free(content);
// 	printf("[OK] Contenido liberado correctamente.\n");
// }
// int	main(void)
// {
// 	// 1. Creamos un nodo y su contenido con malloc
// 	t_list *nodo = malloc(sizeof(t_list));
// 	nodo->content = malloc(10);
// 	nodo->next = NULL;

// 	// 2. Probando la función
// 	ft_lstdelone(nodo, del_content);

// 	// 3. Probando seguridad contra NULL
// 	ft_lstdelone(NULL, del_content);

// 	printf("Test completado con éxito.\n");
// 	return (0);
// }