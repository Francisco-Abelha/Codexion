/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 20:03:57 by fgoncal2          #+#    #+#             */
/*   Updated: 2026/11/03 20:05:58 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 9)
		return (printf("Invalid number of args\n"), 1);
	if (!(parse_args(&args, argv)))
		return (1);
	printf("%d\n", args.time_to_burnout);
	printf("%s\n", args.scheduler);
	return (0);
}
