/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*lista;
// 	t_list	*nodo_mundo;
// 	t_list	*nodo_hola;

// 	lista = NULL;
// 	nodo_mundo = ft_lstnew("Mundo");
// 	nodo_hola = ft_lstnew("Hola");

// 	// Metemos "Mundo" (lista ahora vale la dirección de Mundo)
// 	ft_lstadd_front(&lista, nodo_mundo);

// 	// Metemos "Hola" al frente (lista ahora vale la dirección de Hola)
// 	ft_lstadd_front(&lista, nodo_hola);

// 	// 1. El primer nodo es al que apunta 'lista' directamente
// 	printf("Primer nodo: %s\n", (char *)lista->content);

// 	// 2. El segundo nodo es el 'next' del primer nodo
// 	printf("Segundo nodo: %s\n", (char *)lista->next->content);

// 	// 3. Comprobando que el último apunta a NULL
// 	printf("¿El fin es NULL?: %s\n", (lista->next->next == NULL) ? "SI" : "NO");

// 	free(nodo_mundo);
// 	free(nodo_hola);
// 	return (0);
// }