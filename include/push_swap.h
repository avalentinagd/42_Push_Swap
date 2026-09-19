/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:24:56 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/03 17:24:56 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

// Estructura del nodo de la Pila
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Estructura de la Pila
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// Estructura de métricas y estadísticas
typedef struct s_stats
{
    int	bench;
    char	*strategy_name;
    int	total_ops;
    double  disorder;
    int	sa;
    int	sb;
    int	ss;
    int	pa;
    int	pb;
    int	ra;
    int	rb;
    int	rr;
    int	rra;
    int	rrb;
    int	rrr;
}   t_stats;

// Prototipos de funciones para reporte de estadísticas
void	init_stats(t_stats *stats);
void	ft_putstr_stderr(char *str);
void	ft_putnbr_stderr(int n);
void	print_bench_results(t_stats *stats);

// Funciones de gestión de staks (src/stack_utils_i.c)
t_stack	*init_stack(void);
t_node	*stack_new_node(int value);
void    stack_add_top(t_stack *stack, t_node *new_node);
void	stack_add_bottom(t_stack *stack, t_node *new_node);
void	free_stack(t_stack *stack);

// Funciones de gestión de staks (src/stack_utils_ii.c)
t_node  *pop_top(t_stack *stack);
t_node  *pop_bottom(t_stack *stack);

// Funciones de Parseo y Split (src/parse_utils.c)
void	free_split(char **split);
size_t	split_len(char **split);
int		is_valid_number(char *str);
int		parse_long(char *str, long long *out_val);
double	compute_disorder(t_stack *a);

// Detección de Flags (src/parse_flags.c)
int		ft_strcmp(const char *s1, const char *s2);
int		check_flag(char *arg, t_stats *stats);

// Core de Parsing (src/parser.c)
int		process_number(char *str, t_stack *stack);
int		print_error(void);
int		parse_arguments(int argc, char **argv, t_stack *stack_a, t_stats *stats);

// Operations
void	op_sa(t_stack *stack_a, t_stats *stats);
void	op_sb(t_stack *stack_b, t_stats *stats);
void	op_ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void    op_pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void    op_pb(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void    op_ra(t_stack *stack_a, t_stats *stats);
void    op_rb(t_stack *stack_b, t_stats *stats);
void    op_rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void    op_rra(t_stack *stack_a, t_stats *stats);
void    op_rrb(t_stack *stack_b, t_stats *stats);
void    op_rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats);

#endif