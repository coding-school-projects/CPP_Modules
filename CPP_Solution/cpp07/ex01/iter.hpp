/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:43:29 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/12 12:53:26 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>

void iter(T *array, size_t array_length, void(*f)(T const &)) 
{
    for (size_t i = 0; i < array_length; i++) 
	{
        f(array[i]);
    }
}

template <typename T>

void print(const T &elem)
{
    std::cout << elem << std::endl;
}

template <typename T>

void times_two(const T &n) 
{
    std::cout << n * 2 << std::endl;
}
