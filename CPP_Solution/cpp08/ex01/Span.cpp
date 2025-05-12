/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:45 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:22:23 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

/* CONSTRUCTORS, DESTRUCTOR, OPERATOR= */
Span::Span()
: _maxSize(0) {}

Span::Span(unsigned int N)
: _maxSize(N) {}

Span::Span(const Span& other)
: _maxSize(other._maxSize),
	_intVector(other._intVector) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
		_intVector = other._intVector;
    }
    return *this;
}

Span::~Span() {}

// Add a single number
void Span::addNumber(int number) {
    if (_intVector.size() >= _maxSize) {
        throw std::runtime_error("Span is full, cannot add more numbers.");
    }
    _intVector.push_back(number);
}

// Find the shortest span
unsigned int Span::shortestSpan() const {
    if (_intVector.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate a span");
    }
    std::vector<int> sortedVector = _intVector;
    std::sort(sortedVector.begin(), sortedVector.end());
    unsigned int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedVector.size(); i++) {
        unsigned int span = sortedVector[i] - sortedVector[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

// Find the longest path
unsigned int Span::longestSpan() const {
    if (_intVector.size() < 2) {
        throw std::logic_error("Not enough numbers to calculate a span");
    }
    int minNum = *std::min_element(_intVector.begin(), _intVector.end());
    int maxNum = *std::max_element(_intVector.begin(), _intVector.end());
    return maxNum - minNum;
}
    