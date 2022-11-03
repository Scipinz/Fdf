/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:42:25 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/02 14:59:56 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t num)
{
	size_t	i;

	i = 0;
	if (needle == NULL || ft_strlen(needle) == -0)
		return ((char *)haystack);
	if (ft_strlen(needle) > num)
		return (NULL);
	while (i < num)
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > num)
				return (NULL);
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
