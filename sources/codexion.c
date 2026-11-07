/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 20:03:57 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/07 17:09:48 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	test_init(t_simulation *sim)
{
	int	fails;
	int	i;
	int	j;
	int	n;

	fails = 0;
	i = 0;
	j = 0;
	n = sim->rules.number_of_coders;
	while (i < n)
	{
		if (sim->coders[i].id != i + 1)
			fails++;
		if (sim->coders[i].num_compiles != 0)
			fails++;
		if (sim->coders[i].left_dongle != &sim->dongles[(i - 1 + n) % n])
			fails++;
		if (sim->coders[i].right_dongle != &sim->dongles[i])
			fails++;
		if (sim->coders[i].simulation != sim)
			fails++;
		i++;
	}
	while (j < n)
	{
		if (sim->dongles[j].taken != 0)
			fails++;
		if (sim->dongles[j].released_at != 0)
			fails++;
		j++;
	}
	if (sim->sim_over_bool != 0)
		fails++;
	if (fails == 0)
		printf("init OK\n");
	else
		printf("init FAILED: %d checks", fails);
}

int	main(int argc, char **argv)
{
	t_simulation    sim;

	if (argc != 9)
			return (print_error("invalid number of args"), 1);
	if (!parse_args(&sim.rules, argv))
			return (1);
	if (!init_simulation(&sim))
			return (print_error("init failed"), 1);
	test_init(&sim);
	cleanup(&sim);
	return (0);
}
