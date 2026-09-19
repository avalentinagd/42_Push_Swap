/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 05:47:10 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/18 05:47:10 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node  *pop_top(t_stack *stack)
{
    t_node  *extract_node; // nodo a desenganchar

    // si stack es NULL (la pila no existe) o si el stack esta vacío 
    // stack->size == 0, no hay nada que extraer ==> retorna NULL
    if (!stack || stack->size == 0)
        return (NULL);
    // Desenganchar el nodo
    extract_node = stack->top; // Referencia al nodo que vamos a extraer
    stack->top = stack->top->next; // Movemos el puntero top de la pila al siguiente elemento
    // Actualizar referencias
    if (stack->top != NULL)
        stack->top->prev = NULL;
    // Cuando la pila tiene un solo nodo y decidimos sacarlo
    if (stack->top == NULL) // si la cima de la pila ha quedado completamente vacía
        stack->bottom = NULL; // el puntero que marca el fondo de la pila también apuntará a NULL
    // Desconectar el nodo extraído
    extract_node->prev = NULL;
    extract_node->next = NULL;
    stack->size--;
    return (extract_node);
}

t_node  *pop_bottom(t_stack *stack)
{
    t_node  *extract_node; // nodo a desenganchar

    // si stack es NULL (la pila no existe) o si el stack esta vacío 
    // stack->size == 0, no hay nada que extraer ==> retorna NULL
    if (!stack || stack->size == 0)
        return (NULL);
    // Desenganchar el nodo
    extract_node = stack->bottom; // Referencia al nodo que vamos a extraer
    stack->bottom = stack->bottom->prev; // Movemos el puntero bottom de la pila al anterior elemento
    // Actualizar referencias
    if (stack->bottom != NULL)
        stack->bottom->next = NULL;
    // Cuando la pila tiene un solo nodo y decidimos sacarlo
    if (stack->bottom == NULL) // si la cima de la pila ha quedado completamente vacía
        stack->top = NULL; // el puntero que marca el fondo de la pila también apuntará a NULL
    // Desconectar el nodo extraído
    extract_node->prev = NULL;
    extract_node->next = NULL;
    stack->size--;
    return (extract_node);
}