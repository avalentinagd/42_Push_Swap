/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 18:02:23 by angalleg          #+#    #+#             */
/*   Updated: 2026/10/02 18:02:23 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_adaptive(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (stats->disorder < 0.20)
	{
		stats->strategy_name = "Simple / O(n^2)";
		sort_simple(stack_a, stack_b, stats);
	}
	else if (stats->disorder >= 0.20 && stats->disorder < 0.50)
	{
		stats->strategy_name = "Medium / O(n sqrt(n))";
		sort_medium(stack_a, stack_b, stats);
	}
	else if (stats->disorder >= 0.50)
	{
		stats->strategy_name = "Complex / O(n log(n))";
		sort_complex(stack_a, stack_b, stats);
	}
}