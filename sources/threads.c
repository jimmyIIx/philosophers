/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:31 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:41:32 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philo_dead(t_sim *sim, t_philo *philo);
static void	ft_check_philo_status(t_sim *sim, t_philo *philo, int i);
static void	exit_threads(t_sim *sim);
static int	check_all(t_sim *d);

void	begin_thread(t_sim *sim)
{
	int	i;

	i = -1;
	sim->start = whats_time();
	while (++i < sim->philo_nbr)
	{
		sim->philos[i].last_eating = whats_time();
		if (pthread_create(&sim->philos[i].thread_id,
				NULL, thread_routine, &(sim->philos[i])))
		{
			write_error("Error: Failed to create threads");
			return ;
		}
	}
	ft_philo_dead(sim, sim->philos);
	pthread_mutex_unlock(&sim->writing);
	exit_threads(sim);
}

static void	ft_philo_dead(t_sim *sim, t_philo *philo)
{
	int	i;

	while (!sim->max_dish)
	{
		i = -1;
		while (++i < sim->philo_nbr && !sim->end)
			ft_check_philo_status(sim, philo, i);
		if (sim->end)
			break ;
		sim->max_dish = check_all(sim);
	}
}

static void	ft_check_philo_status(t_sim *sim, t_philo *philo, int i)
{
	pthread_mutex_lock(&sim->dish);
	if ((int)(whats_time() - philo[i].last_eating) >= sim->time_to_die)
	{
		ft_print_philo(&philo[i], "died");
		sim->end = 1;
	}
	pthread_mutex_unlock(&sim->dish);
}

static int	check_all(t_sim *d)
{
	int	i;

	i = 0;
	while (d->count_eat && i < d->philo_nbr
		&& d->philos[i].dish_t >= d->count_eat)
		i++;
	return (i == d->philo_nbr);
}

static void	exit_threads(t_sim *sim)
{
	int	i;

	if (sim->philo_nbr == 1)
		pthread_detach(sim->philos[0].thread_id);
	else
	{
		i = -1;
		while (++i < sim->philo_nbr)
			pthread_join(sim->philos[i].thread_id, NULL);
	}
	free_resources(sim);
}
