/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:08 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:39:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_init_mutex(t_sim *sim);
static void	ft_philo_init(t_sim *sim);
static void	ft_free_resources(t_sim *sim);
static void	ft_free_and_error(t_sim *sim, const char *error_message);

void	ft_init(t_sim *sim)
{
	sim->philos = ft_malloc(sizeof(t_philo) * sim->philo_nbr);
	if (!sim->philos)
		ft_free_and_error(sim, "Error: Failed to allocate philosophers");
	sim->forks = ft_malloc(sizeof(pthread_mutex_t) * sim->philo_nbr);
	if (!sim->forks)
		ft_free_and_error(sim, "Error: Failed to allocate forks");
	ft_init_mutex(sim);
	ft_philo_init(sim);
}

static void	ft_init_mutex(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_nbr)
	{
		if (pthread_mutex_init(&(sim->forks[i]), NULL))
			ft_free_and_error(sim, "Error: Failed to initialize fork mutex");
		i++;
	}
	if (pthread_mutex_init(&sim->dish, NULL))
		ft_free_and_error(sim, "Error: Failed to initialize meal mutex");
	if (pthread_mutex_init(&sim->writing, NULL))
		ft_free_and_error(sim, "Error: Failed to initialize writing mutex");
}

static void	ft_philo_init(t_sim *sim)
{
	int	i;
	int	j;

	i = 0;
	while (i < sim->philo_nbr)
	{
		sim->philos[i].dish_t = 0;
		sim->philos[i].id = i + 1;
		sim->philos[i].id_str = ft_itoa(i + 1);
		if (!sim->philos[i].id_str)
		{
			j = 0;
			while (j < i)
			{
				free(sim->philos[j].id_str);
				j++;
			}
			ft_free_and_error(sim, "Error: Failed to allocate id string");
		}
		sim->philos[i].first_fork = i;
		sim->philos[i].second_fork = (i + 1) % sim->philo_nbr;
		sim->philos[i].sim = sim;
		i++;
	}
}

static void	ft_free_resources(t_sim *sim)
{
	if (sim->philos)
		free(sim->philos);
	if (sim->forks)
		free(sim->forks);
}

static void	ft_free_and_error(t_sim *sim, const char *error_message)
{
	ft_free_resources(sim);
	write_error(error_message);
}
