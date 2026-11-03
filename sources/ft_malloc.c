/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:31:33 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:31:46 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		write_error("Malloc error");
	return (ptr);
}
