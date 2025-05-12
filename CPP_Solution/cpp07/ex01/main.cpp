/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:43:15 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/12 12:45:34 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) 
{
    int array[] = {1, 2, 3, 4, 5};
    size_t array_length = sizeof(array)/sizeof(array[0]);

    ::iter(array, array_length, times_two);

    std::string strings[] = {"Hello", "Hive", "Helsinki"};
    size_t strings_length = sizeof(strings)/sizeof(strings[0]);

    ::iter(strings, strings_length, print);

    return 0;
}