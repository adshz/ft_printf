/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:13:04 by szhong            #+#    #+#             */
/*   Updated: 2024/01/22 14:08:15 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Duplicates a string.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL on failure.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;

	if (!s || !*s)
		return (0);
	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	ptr = dup;
	while (*s)
	{
		*ptr++ = *s++;
	}
	*ptr = '\0';
	return (dup);
}
