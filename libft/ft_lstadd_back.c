/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node_hello;
// 	t_list	*node_world;

// 	list = NULL;
// 	node_hello = ft_lstnew("Hello");
// 	node_world = ft_lstnew("World");

// 	// TEST 1: Primero añadimos a la lista vacía el node_hello
// 	ft_lstadd_back(&list, node_hello);
// 	printf("1. Primer nodo (debe ser Hola): %s\n", (char *)list->content);

// 	// TEST 2: Añadimos al final node_world, detrás de node_hello)
// 	ft_lstadd_back(&list, node_world);
// 	printf("2. Segundo nodo (debe ser Mundo): %s\n", 
// 			(char *)list->next->content);

// 	// TEST 3: Comprobar que el final vuelve a ser NULL
// 	printf("3. ¿El siguiente del último es NULL?: %s\n", 
// 			(list->next->next == NULL) ? "SI" : "NO");

// 	free(node_hello);
// 	free(node_world);
// 	return (0);
// }