/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:51:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/03 13:51:56 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* CONSTRUCTORS */

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int intVal)
{
	this->_fixedPointValue = intVal << this->_fractionalBits;
}

Fixed::Fixed(const float floatVal)
{
	this->_fixedPointValue = roundf((floatVal * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

/* OVERLOADING OPERATORS */

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

/* DESTRUCTOR */

Fixed::~Fixed() {}

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum)
{
	out << fixedNum.toFloat();
	return out;
}

// Overloading 6 comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

// Overloading 4 arithmetic operators: +, -, *, and /

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;
    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return result;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;
    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return result;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;
    result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0)
	{
		std::cout << "Cannot divide by ";
		return 0;
	}
	Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
    return result;
}

// Overloading pre-increment operator

Fixed&	Fixed::operator++()
{
	++_fixedPointValue;
	return *this;
}

// Overloading post-increment operator

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_fixedPointValue;
	return tmp;
}

// Overloading pre-decrement operator

Fixed&	Fixed::operator--()
{
	--_fixedPointValue;
	return *this;
}

// Overloading post-decrement operator

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_fixedPointValue;
	return tmp;
}

/* OVERLOADED MEMBER FUNCS ON MAX, MIN */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

/* OTHER MEMBER FUNCS */

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}