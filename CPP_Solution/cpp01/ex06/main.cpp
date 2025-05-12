/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:18:03 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/28 14:22:04 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments\n";
		std::cout << "Usage: " << argv[0] << " <level>\n";
		return (1);
	}
	Harl	harl;
    harl.complain(argv[1]);
	return (0);
}