/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
}

// #include <stdio.h>
// void	free_content(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	// Creamos 2 nodos y 2 contenidos en el heap
// 	t_list *nodo1 = malloc(sizeof(t_list));
// 	t_list *nodo2 = malloc(sizeof(t_list));

// 	nodo1->content = malloc(10); // Reservamos 10 bytes de memoria "vacía"
// 	nodo2->content = malloc(10); // Reservamos 10 bytes de memoria "vacía"

// 	nodo1->next = nodo2;
// 	nodo2->next = NULL;

// 	t_list *mi_lista = nodo1;

// 	// Borrado completo y reseteo a NULL
// 	ft_lstclear(&mi_lista, free_content);

// 	if (mi_lista == NULL)
// 		printf("Test 1: Lista liberada y puntero en NULL: OK\n");

// 	// Protecciones contra NULL
// 	ft_lstclear(NULL, free_content);

// 	t_list *lista_vacia = NULL;
// 	ft_lstclear(&lista_vacia, free_content);

// 	printf("Test 2: Protecciones contra NULL: OK\n");

// 	return (0);
// }