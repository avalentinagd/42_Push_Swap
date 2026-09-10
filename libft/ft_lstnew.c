/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*nodo_str;
// 	t_list	*nodo_num;
// 	t_list	*nodo_null;
// 	int		number = 23;

// 	// CASO 1: Cadena de texto
// 	nodo_str = ft_lstnew("OK");
// 	if (nodo_str)
// 		printf("Nodo 1 (String): %s | Next: %p\n", 
//				(char *)nodo_str->content, nodo_str->next);

// 	// CASO 2: Dirección de un entero
// 	nodo_num = ft_lstnew(&number);
// 	if (nodo_num)
// 		printf("Nodo 2 (Int):    %d | Next: %p\n", 
//				*(int *)nodo_num->content, nodo_num->next);

// 	// CASO CRÍTICO 3: Contenido NULL explícito
// 	nodo_null = ft_lstnew(NULL);
// 	if (nodo_null)
// 	{
// 		printf("Nodo 3 (NULL):   %p | Next: %p\n", 
//				nodo_null->content, nodo_null->next);
// 	}

// 	free(nodo_str);
// 	free(nodo_num);
// 	free(nodo_null);

// 	return (0);
// }