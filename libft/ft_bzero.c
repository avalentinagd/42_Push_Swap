/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:50:29 by angalleg          #+#    #+#             */
/*   Updated: 2026/06/10 17:33:44 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest_str;
	size_t			i;

	i = 0;
	dest_str = (unsigned char *)s;
	while (i < n)
	{
		dest_str[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	buffer[10] = "holA MUNDO";

// 	ft_bzero(buffer, 2);
// 	return (0);
// }
