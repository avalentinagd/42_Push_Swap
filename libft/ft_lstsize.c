/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*nodo1;
// 	t_list	*nodo2;
// 	t_list	*nodo3;
// 	t_list	*lista_vacia;

// 	lista_vacia = NULL;
// 	printf("CASO 1 Tamaño lista vacía: %d (Debe ser 0)\n", 
//			ft_lstsize(lista_vacia));

// 	nodo1 = ft_lstnew("Uno");
// 	nodo2 = ft_lstnew("Dos");
// 	nodo3 = ft_lstnew("Tres");

// 	nodo1->next = nodo2;
// 	nodo2->next = nodo3;
// 	nodo3->next = NULL;

// 	printf("CASO 2 Tamaño de la lista (de 3 nodos): %d (Debe ser 3)\n", 
//			ft_lstsize(nodo1));

// 	free(nodo1);
// 	free(nodo2);
// 	free(nodo3);
// 	return (0);
// }