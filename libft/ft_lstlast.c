/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*last;

// 	printf("Caso lista vacía: %p (Debe ser 0x0 o NULL)\n", ft_lstlast(NULL));

// 	node1 = ft_lstnew("Uno");
// 	node2 = ft_lstnew("Dos");
// 	node3 = ft_lstnew("Tres");

// 	// Encadenamiento manual (nodo1 -> nodo2 -> nodo3 -> NULL)
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;

// 	// Probamos la función
// 	last = ft_lstlast(node1);

// 	printf("Contenido del último nodo: %s (Debe ser Tres)\n", 
//			(char *)last->content);
// 	printf("El siguiente del último es NULL?: %s\n", 
//			(last->next == NULL) ? "SI" : "NO");

// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return (0);
// }