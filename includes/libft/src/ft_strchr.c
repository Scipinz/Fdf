/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:36:32 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/03 13:26:13 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!str || !c)
		return (NULL);
	len = ft_strlen(str);
	if (c == '\0')
		return (&((char *)str)[len]);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i + 1]);
		i++;
	}
	return (NULL);
}
