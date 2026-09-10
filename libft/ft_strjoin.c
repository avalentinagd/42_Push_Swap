/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 21:42:47 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:41:26 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_mem;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new_mem = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_mem)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_mem[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_mem[i + j] = s2[j];
		j++;
	}
	new_mem[i + j] = '\0';
	return (new_mem);
}
