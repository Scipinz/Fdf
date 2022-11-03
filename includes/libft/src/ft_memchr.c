/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:12:55 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/03 13:03:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t num)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)src;
	i = 0;
	if (!src)
		return (NULL);
	while (i < num)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)src + i);
		i++;
	}
	return (NULL);
}

// COMMENTS:

// unsigned char *ptr has to be made to convert const void *s
// to an unsigned char *, which is initialized with p. this is
// because otherwise in the if statement s[i] would be a
// const void * and could not be compared to c which is an int.
// char has int value.
