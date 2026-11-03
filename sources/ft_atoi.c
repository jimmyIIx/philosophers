/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:55:41 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:40:40 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int			ft_is_digit(char c);
static int			ft_is_space(char c);
static const char	*ft_check_sign_and_spaces(const char *str, int *i);
static const char	*ft_pre_check_atoi(const char *str);

int	ft_atoi(const char *str)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = 0;
	str = ft_pre_check_atoi(str);
	while (ft_is_digit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > INT_MAX)
			write_error("Error: number too high\n");
		i++;
	}
	return ((int)nbr);
}

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

static const char	*ft_check_sign_and_spaces(const char *str, int *i)
{
	while (ft_is_space(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			write_error("Error: we need a positive value\n");
		(*i)++;
	}
	return (str);
}

static const char	*ft_pre_check_atoi(const char *str)
{
	int			size;
	int			i;
	const char	*nbr;

	i = 0;
	size = 0;
	str = ft_check_sign_and_spaces(str, &i);
	if (!ft_is_digit(str[i]))
		write_error("Error: we need a number\n");
	nbr = &str[i];
	while (ft_is_digit(str[i]))
	{
		size++;
		i++;
	}
	if (size > 10)
		write_error("Error: number too big\n");
	if (str[i] != '\0')
		write_error("Error: invalid character detected\n");
	return (nbr);
}
