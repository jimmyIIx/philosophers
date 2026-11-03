/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:54:25 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:40:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_resources(t_sim *d)
{
	int	i;

	if (d->count_eat && !d->end)
		printf("\nEach philosopher has eaten %ld times\n", d->count_eat);
	i = -1;
	while (++i < d->philo_nbr)
		pthread_mutex_destroy(&d->forks[i]);
	pthread_mutex_destroy(&d->dish);
	pthread_mutex_destroy(&d->writing);
	i = -1;
	while (++i < d->philo_nbr)
		free(d->philos[i].id_str);
	free(d->philos);
	free(d->forks);
}
