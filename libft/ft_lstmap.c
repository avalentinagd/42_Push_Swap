/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// #include <stdio.h>
// void	f_del(void *content)
// {
// 	free(content);
// }

// void	*f_duplicar(void *c)
// {
// 	int *n = malloc(sizeof(int));
// 	if (n)
// 		*n = *(int *)c * 2;
// 	return (n);
// }

// int	main(void)
// {
// 	int a = 10;
// 	int b = 20;

// 	// Crear lista original
// 	t_list *orig = ft_lstnew(&a);
// 	ft_lstadd_back(&orig, ft_lstnew(&b));

// 	// Probar ft_lstmap
// 	t_list *map = ft_lstmap(orig, f_duplicar, f_del);

// 	// Imprimir resultados
// 	printf("Orig: %d -> %d\n", *(int *)orig->content, 
//			*(int *)orig->next->content);
// 	printf("Map:  %d -> %d\n", *(int *)map->content, 
//			*(int *)map->next->content);

// 	// Limpieza minimalista manual
// 	free(map->next->content);
// 	free(map->next);
// 	free(map->content);
// 	free(map);
// 	free(orig->next);
// 	free(orig);

// 	return (0);
// }