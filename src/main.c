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

int	main(int argc, char **argv)
{
	t_stats	stats;
	int			i;

	init_stats(&stats);
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		check_flag(argv[i], &stats);
		i++;
	}
	print_bench_results(&stats, 0.45);
	return (0);
}