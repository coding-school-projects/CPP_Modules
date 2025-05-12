/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:55 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:23:24 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack &other):std::stack<T>(other) {};
		MutantStack &operator=(const MutantStack &other)
		{
			if (other != *this) {
				this->c = other.c;
			}
			return *this;
		};
		~MutantStack() {
			this->c.clear();
		};

		// type aliases for iterator types
		using iterator = typename std::deque<T>::iterator;
		using const_iterator = typename std::deque<T>::const_iterator;
		
		iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }	
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};

#endif