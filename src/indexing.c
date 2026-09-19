/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 17:22:43 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/19 17:22:43 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void index_stack(t_stack *stack_a)
{
    t_node  *curr;
    t_node  *check;
    int index;

    if (!stack_a || stack_a->size == 0)
        return ;
    curr = stack_a->top;
    while(curr)
    {
        index = 0;
        check = stack_a->top; // siempre evaluaremos el nodo check desde el tope de la pila
        while(check)
        {
            if (curr->value > check->value)
                index++;
            check = check->next;
        }
        curr->index = index;
        curr = curr->next;
    }
}