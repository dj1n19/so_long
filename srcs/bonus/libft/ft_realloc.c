/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:04:32 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/20 11:55:09 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_alloc;
	void	*save;

	if (!ptr)
		return (NULL);
	new_alloc = (void *) malloc(sizeof(*ptr) * size);
	if (!new_alloc)
		return (NULL);
	save = new_alloc;
	while (size--)
	{
		*(unsigned char *)new_alloc++ = *(unsigned char *)ptr++;
	}
	return (save);
}
