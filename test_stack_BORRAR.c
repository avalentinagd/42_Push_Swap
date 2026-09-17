/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:47:10 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/08 18:47:10 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

// Esta función sirve para mirar el estado de la pila en cualquier momento
//  y verificar que los punteros apunten a donde deben.
void    print_stack_debug(t_stack *stack, char *name)
{
    t_node  *curr;

    if (!stack) // Por si la pila no se pudo inicializar o no existe, para evitar un segmentation fault.
    {
        printf("Pila %s es NULL\n", name);
        return ;
    }
    printf("\n--- ESTADO DE LA PILA %s (Size: %d) ---\n", name, stack->size); // stack->size: Imprime el número total de nodos que la pila cree tener.
    if (stack->top) // stack->top: Muestra qué valor tiene el primer elemento de la cima.
        printf("TOP -> Value: %d\n", stack->top->value);
    else
        printf("TOP -> NULL\n");

    if (stack->bottom) // stack->bottom: Muestra qué valor tiene el elemento del fondo.
        printf("BOTTOM -> Value: %d\n", stack->bottom->value);
    else
        printf("BOTTOM -> NULL\n");

    printf("Recorrido TOP -> BOTTOM (next): ");
    curr = stack->top;
    while (curr)
    {
        printf("[%d] ", curr->value);
        curr = curr->next;
    }
    printf("\n");

    printf("Recorrido BOTTOM -> TOP (prev): ");
    curr = stack->bottom;
    while (curr)
    {
        printf("[%d] ", curr->value);
        curr = curr->prev;
    }
    printf("\n---------------------------------------\n");
}

//  cc -Wall -Wextra -Werror -I include -I libft test_stack_BORRAR.c src/stack_utils.c -o test_stack
//  Verificar ausencia total de leaks mediante Valgrind: valgrind --leak-check=full --show-leak-kinds=all ./test_stack

int main(void)
{
    t_stack *a;

    printf("=== TEST 1: Inicialización de pila ===\n");
    a = init_stack();
    if (!a)
    {
        printf("Error al asignar memoria a la pila\n");
        return (1);
    }
    print_stack_debug(a, "A (Vacía)");

    printf("\n=== TEST 2: Inserción abajo (add_bottom: 10, 20, 30) ===\n");
    stack_add_bottom(a, stack_new_node(10));
    stack_add_bottom(a, stack_new_node(20));
    stack_add_bottom(a, stack_new_node(30));
    print_stack_debug(a, "A");

    printf("\n=== TEST 3: Inserción arriba (add_top: 5) ===\n");
    stack_add_top(a, stack_new_node(5));
    print_stack_debug(a, "A");

    printf("\n=== TEST 4: Liberar pila ===\n");
    free_stack(a);
    printf("Pila liberada correctamente.\n");

    return (0);
}