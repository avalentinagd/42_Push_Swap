/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 00:39:54 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/07 00:39:54 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stats	stats;
// 	int			i;

// 	init_stats(&stats);
// 	if (argc < 2)
// 		return (0);
// 	i = 1;
// 	while (i < argc)
// 	{
// 		check_flag(argv[i], &stats);
// 		i++;
// 	}
// 	print_bench_results(&stats);
// 	return (0);
// }

// Función auxiliar para imprimir el contenido de una pila de top a bottom
static void	print_stack(char *name, t_stack *stack)
{
	t_node	*curr;

	printf("%s: [ ", name);
	if (stack)
	{
		curr = stack->top;
		while (curr)
		{
			printf("%d(%d) ", curr->value, curr->index);
			curr = curr->next;
		}
	}
	printf("]\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stats	stats;

	if (argc < 2)
		return (0);
	init_stats(&stats);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (print_error());
	if (!parse_arguments(argc, argv, stack_a, &stats))
		return (free_stack(stack_a), free_stack(stack_b), 0);
	index_stack(stack_a);

	printf("\n=== ESTADO INICIAL ===\n");
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n=== PRUEBA PUSH (pb, pb) ===\n");
	op_pb(stack_a, stack_b, &stats);
	op_pb(stack_a, stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n=== PRUEBA SWAP (sa, sb, ss) ===\n");
	op_sa(stack_a, &stats);
	op_sb(stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);
	op_ss(stack_a, stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n=== PRUEBA ROTATE (ra, rb, rr) ===\n");
	op_ra(stack_a, &stats);
	op_rb(stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n=== PRUEBA REVERSE ROTATE (rra, rrb, rrr) ===\n");
	op_rra(stack_a, &stats);
	op_rrb(stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n=== PRUEBA PUSH BACK (pa, pa) ===\n");
	op_pa(stack_a, stack_b, &stats);
	op_pa(stack_a, stack_b, &stats);
	print_stack("A", stack_a);
	print_stack("B", stack_b);

	printf("\n Total de operaciones ejecutadas: %d\n", stats.total_ops);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// make
// ./push_swap 10 20 30 40