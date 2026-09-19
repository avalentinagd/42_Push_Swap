/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:36:05 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/03 18:36:05 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Inicializa todos los valores en 0
void    init_stats(t_stats *stats)
{
    stats->bench = 0;
    stats->strategy_name = "Adaptive"; // Nombre por defecto
    stats->total_ops = 0;
	stats->disorder = 0.0;
    stats->sa = 0;
    stats->sb = 0;
    stats->ss = 0;
    stats->pa = 0;
    stats->pb = 0;
    stats->ra = 0;
    stats->rb = 0;
    stats->rr = 0;
    stats->rra = 0;
    stats->rrb = 0;
    stats->rrr = 0;
}

// Función auxiliar para imprimir strings en stderr (fd 2)
void ft_putstr_stderr(char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
        i++;
    write(2, str, i); // write con fd = 2 escribe en stderr
}

// Función auxiliar para imprimir enteros en stderr (fd 2)
void	ft_putnbr_stderr(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putstr_stderr("-");
		if (n == -2147483648)
		{
			ft_putstr_stderr("2147483648");
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_stderr(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	operations_stats(t_stats *stats)
{
	// 4. Desglose de operaciones: veces que se ejecuta cada instrucción durante el proceso de ordenación.
	ft_putstr_stderr("[bench] sa: ");
	ft_putnbr_stderr(stats->sa);
	ft_putstr_stderr(" sb: ");
	ft_putnbr_stderr(stats->sb);
	ft_putstr_stderr(" ss: ");
	ft_putnbr_stderr(stats->ss);
	ft_putstr_stderr(" pa: ");
	ft_putnbr_stderr(stats->pa);
	ft_putstr_stderr(" pb: ");
	ft_putnbr_stderr(stats->pb);
	ft_putstr_stderr("\n");
	ft_putstr_stderr("[bench] ra: ");
	ft_putnbr_stderr(stats->ra);
	ft_putstr_stderr(" rb: ");
	ft_putnbr_stderr(stats->rb);
	ft_putstr_stderr(" rr: ");
	ft_putnbr_stderr(stats->rr);
	ft_putstr_stderr(" rra: ");
	ft_putnbr_stderr(stats->rra);
	ft_putstr_stderr(" rrb: ");
	ft_putnbr_stderr(stats->rrb);
	ft_putstr_stderr(" rrr: ");
	ft_putnbr_stderr(stats->rrr);
	ft_putstr_stderr("\n");
}

// Imprime el reporte obligatorio en stderr si la flag bench está encendida
void	print_bench_results(t_stats *stats)
{
	if (!stats || !stats->bench)
		return ;

	// 1. Mostrar desorden (multiplicado por 100 para porcentaje)
	ft_putstr_stderr("[bench] disorder: ");
	ft_putnbr_stderr((stats->disorder * 100));
	ft_putstr_stderr("\n");

	// 2. Mostrar estrategia
	ft_putstr_stderr("[bench] strategy: ");
	ft_putstr_stderr(stats->strategy_name);
	ft_putstr_stderr("\n");

	// 3. Mostrar total de operaciones
	ft_putstr_stderr("[bench] total_ops: ");
	ft_putnbr_stderr(stats->total_ops);
	ft_putstr_stderr("\n");

	operations_stats(stats);
}
