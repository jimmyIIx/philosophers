/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:17 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:21:18 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_calloc(size_t count, size_t size);
static void	ft_bzero(void *s, size_t n);
static int	ft_get_len(int number, int *nonpositive_ptr);
static void	ft_fill(char *string, int last, int number, int negative);

char	*ft_itoa(int number)
{
	int		len;
	int		nonpositive;
	char	*string;

	len = ft_get_len(number, &nonpositive);
	string = ft_calloc((size_t)(len), sizeof(char));
	if (!string)
		return (NULL);
	if (number == 0)
		string[0] = '0';
	if (number < 0)
		string[0] = '-';
	ft_fill(string, (len - 2), number, nonpositive);
	return (string);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

static int	ft_get_len(int number, int *nonpositive_ptr)
{
	int	len;

	if (number <= 0)
		*nonpositive_ptr = 1;
	else
		*nonpositive_ptr = 0;
	len = 1;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len + *nonpositive_ptr);
}

static void	ft_fill(char *string, int last, int number, int negative)
{
	while (number)
	{
		if (negative)
			string[last--] = 48 + ((number % 10) * (-1));
		else
			string[last--] = 48 + (number % 10);
		number /= 10;
	}
}
