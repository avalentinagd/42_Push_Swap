/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// void	f_uppercase(void *content)
// {
// 	char *c = (char *)content;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

// int	main(void)
// {
// 	char letra1 = 'x';
// 	char letra2 = 'y';

// 	// Creamos 2 nodos
// 	t_list *nodo1 = malloc(sizeof(t_list));
// 	t_list *nodo2 = malloc(sizeof(t_list));

// 	// Los conectamos
// 	nodo1->content = &letra1;
// 	nodo1->next = nodo2;

// 	nodo2->content = &letra2;
// 	nodo2->next = NULL;

// 	printf("Antes:   %c y %c\n", *(char *)nodo1->content, 
//			*(char *)nodo2->content);
// 	ft_lstiter(nodo1, f_uppercase);
// 	printf("Después: %c y %c \n", *(char *)nodo1->content, 
//			*(char *)nodo2->content);

// 	free(nodo1);
// 	free(nodo2);

// 	return (0);
// }