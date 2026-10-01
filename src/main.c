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
// static void	print_stack(char *name, t_stack *stack)
// {
// 	t_node	*curr;

// 	printf("%s: [ ", name);
// 	if (stack)
// 	{
// 		curr = stack->top;
// 		while (curr)
// 		{
// 			printf("%d(%d) ", curr->value, curr->index);
// 			curr = curr->next;
// 		}
// 	}
// 	printf("]\n");
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	t_stats	stats;

// 	if (argc < 2)
// 		return (0);
// 	init_stats(&stats);
// 	stack_a = init_stack();
// 	stack_b = init_stack();
// 	if (!stack_a || !stack_b)
// 		return (print_error());
// 	if (!parse_arguments(argc, argv, stack_a, &stats))
// 		return (free_stack(stack_a), free_stack(stack_b), 0);
// 	index_stack(stack_a);
// 	stats.disorder = compute_disorder(stack_a);
// 	//sort_simple(stack_a, stack_b, &stats);
// 	//sort_medium(stack_a, stack_b, &stats);
// 	sort_complex(stack_a, stack_b, &stats);
// 	printf("\n Stack A ordenado: \n");
// 	print_stack("A", stack_a);
// 	print_stack("B", stack_b);
// 	printf("\n Total de operaciones ejecutadas: %d\n", stats.total_ops);
	
// 	print_bench_results(&stats);

// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return (0);
// }

// make
// ./push_swap 10 20 30 40
// Para complex:
// ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap --bench --complex $ARG
// ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap --bench --complex $ARG

// Main para probar el checker
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

	//sort_medium(stack_a, stack_b, &stats);
	sort_complex(stack_a, stack_b, &stats);
	free_stack(stack_a);
 	free_stack(stack_b);
	return (0);
}
// para probar el checker
// make
// intermedio:
// ARG="48 12 89 3 95 27 61 14 78 33 50 9 82 41 67 22 90 5 73 38 100 17 64 29 85 52 8 71 44 96 20 60 35 88 11 75 49 2 93 26 58 15 81 37 69 24 99 6 74 43 87 19 63 31 92 55 1 70 42 84 18 57 32 97 10 77 46 86 23 62 36 91 4 72 45 80 13 66 28 98 51 7 76 40 83 25 59 16 94 39 68 21 79 47 500 30 54 34 65 53"; ./push_swap --medium $ARG | ./checker_linux $ARG
// Complejo:
// ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap --complex $ARG | ./checker_linux $ARG
// ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap --complex $ARG | ./checker_linux $ARG

