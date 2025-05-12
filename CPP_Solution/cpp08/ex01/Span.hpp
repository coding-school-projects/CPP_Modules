/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:47 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:22:01 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
// #include <stdexcept>

class Span
{
	private:
	    unsigned int _maxSize; 
	    std::vector<int> _intVector;

	public:
		// Constructor & Destructor
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		// Member Functions
		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template<typename T>
		void addMultipleNumbers(T beginIt, T endIt) {    
    		if (_intVector.size() + std::distance(beginIt, endIt) > _maxSize) {
        		throw std::runtime_error("Span is full, cannot add more numbers.");
    		}
    		_intVector.insert(_intVector.end(), beginIt, endIt);
		}		

		void printNumbers() const;
};

#endif