/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:32:46 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:11 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_isascii('a'));
// 	printf("%d\n", ft_isascii('*'));
// 	printf("%d\n", ft_isascii('5'));
// 	printf("%d", ft_isascii('='));
// 	return (0);
// }
