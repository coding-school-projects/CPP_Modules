/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:36 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:48:33 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;
	
	public:
	
	Fixed();
	~Fixed();
	Fixed(const int n);
	Fixed(const float n);

	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed &other);

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &first, Fixed &other);
	static const Fixed &min(const Fixed &first, const Fixed &other);
	static Fixed &max(Fixed &first, Fixed &other);
	static const Fixed &max(const Fixed &first, const Fixed &other);

	Fixed abs() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif