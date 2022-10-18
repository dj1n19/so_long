/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:11:55 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/15 17:50:06 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*dst_bytes;
	unsigned char	*src_bytes;

	if (!src && !dst)
		return (NULL);
	dst_bytes = (unsigned char *)dst;
	src_bytes = (unsigned char *)src;
	while (n--)
		*dst_bytes++ = *src_bytes++;
	return (dst);
}
