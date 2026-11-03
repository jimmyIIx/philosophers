/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:12:10 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 12:41:56 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_sim	t_sim;

typedef struct s_philo
{
	char			*id_str;
	long			dish_t;
	long			id;
	long			first_fork;
	long			second_fork;
	unsigned long	last_eating;
	pthread_t		thread_id;
	t_sim			*sim;
}					t_philo;

typedef struct s_sim
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			count_eat;
	long			start;
	long			end;
	long			max_dish;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dish;
	pthread_mutex_t	writing;
}					t_sim;

void	ft_parse(int argc, char **argv, t_sim *sim);
void	ft_init(t_sim *sim);
long	whats_time(void);
void	*thread_routine(void *routine);
void	begin_thread(t_sim *sim);

//utils

void	write_error(const char *error);
void	ft_usleep(long duration, t_sim *sim);
void	ft_print_philo(t_philo *philo, char *msg);
long	whats_time(void);

// Autre

void	free_resources(t_sim *d);
void	*ft_malloc(size_t size);
char	*ft_itoa(int number);
int		ft_atoi(const char *str);

#endif
