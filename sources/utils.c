/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 13:21:49 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_error(const char *error)
{
	printf(" %s\n", error);
	exit(EXIT_FAILURE);
}

void	ft_usleep(long duration, t_sim *sim)
{
	long	start;

	start = whats_time();
	while (!sim->end)
	{
		if (whats_time() - start >= duration)
			break ;
		usleep(sim->philo_nbr * 2);
	}
}

void	ft_print_philo(t_philo *philo, char *msg)
{
	char	*time;

	pthread_mutex_lock(&philo->sim->writing);
	if (philo->sim->end || philo->sim->max_dish)
	{
		pthread_mutex_unlock(&philo->sim->writing);
		return ;
	}
	time = ft_itoa(whats_time() - philo->sim->start);
	if (!time)
	{
		pthread_mutex_unlock(&philo->sim->writing);
		return ;
	}
	printf("%sms %s %s\n", time, philo->id_str, msg);
	free(time);
	pthread_mutex_unlock(&philo->sim->writing);
}

long	whats_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
