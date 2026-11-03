/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:40:54 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:47:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	ft_check_params(t_sim *sim);

void	ft_parse(int argc, char **argv, t_sim *sim)
{
	sim->philo_nbr = ft_atoi(argv[1]);
	sim->time_to_die = ft_atoi(argv[2]);
	sim->time_to_eat = ft_atoi(argv[3]);
	sim->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->count_eat = ft_atoi(argv[5]);
	else
		sim->count_eat = 0;
	if (ft_check_params(sim))
		write(STDERR_FILENO, "Error: Invalid parameters\n", 26);
}

static bool	ft_check_params(t_sim *sim)
{
	if (sim->philo_nbr <= 0 \
		|| sim->time_to_die < 0 \
		|| sim->time_to_eat < 0 \
		|| sim->time_to_sleep < 0 \
		|| sim->count_eat < 0)
		return (true);
	return (false);
}
