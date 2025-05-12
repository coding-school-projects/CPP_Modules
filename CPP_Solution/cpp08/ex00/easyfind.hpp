/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:29 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:21:01 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // find
#include <string>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	// Iterator pointing to the found value, or endIt if not found
	auto foundIt = std::find(container.begin(), container.end(), value);
	
	if (foundIt == container.end())  // If value is not found
		throw std::runtime_error("\e[0;31mValue " + std::to_string(value) + " not found\e[0m");
	return (foundIt);
}

#endif