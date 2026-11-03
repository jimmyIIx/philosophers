/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:28:47 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/22 11:41:43 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	sim.end = 0;
	sim.max_dish = 0;
	if (argc == 5 || argc == 6)
	{
		ft_parse(argc, argv, &sim);
		ft_init(&sim);
		begin_thread(&sim);
	}
	else
		write(STDERR_FILENO, "Error : wrong input\n", 20);
}
