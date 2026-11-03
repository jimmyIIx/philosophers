/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:42 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 13:16:06 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philo_eat(t_philo *philo);
static void	ft_philo_life_cycle(t_philo *philo);

void	*thread_routine(void *routine)
{
	t_philo	*philo;

	philo = (t_philo *)routine;
	if (philo->id % 2 && philo->sim->philo_nbr > 1)
		ft_usleep(philo->sim->time_to_eat / 50, philo->sim);
	ft_philo_life_cycle(philo);
	return (NULL);
}

static void	ft_philo_life_cycle(t_philo *philo)
{
	while (!philo->sim->end && !philo->sim->max_dish)
	{
		ft_philo_eat(philo);
		ft_print_philo(philo, "is sleeping");
		ft_usleep(philo->sim->time_to_sleep, philo->sim);
		ft_print_philo(philo, "is thinking");
	}
}

static void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim->forks[philo->first_fork]);
	ft_print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->sim->forks[philo->second_fork]);
	ft_print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->sim->dish);
	ft_print_philo(philo, "is eating");
	philo->last_eating = whats_time();
	pthread_mutex_unlock(&philo->sim->dish);
	ft_usleep(philo->sim->time_to_eat, philo->sim);
	philo->dish_t++;
	pthread_mutex_unlock(&philo->sim->forks[philo->second_fork]);
	pthread_mutex_unlock(&philo->sim->forks[philo->first_fork]);
}
