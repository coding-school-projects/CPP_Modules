/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:42:43 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/12 11:39:36 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>

void swap(T& a, T& b) 
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>

const T& max(const T& a, const T& b) 
{
	if (a > b) return a;
	return b;
}

template<typename T>

const T& min(const T& a, const T& b) 
{
	if (a < b) return a;
	return b;
}

#endif