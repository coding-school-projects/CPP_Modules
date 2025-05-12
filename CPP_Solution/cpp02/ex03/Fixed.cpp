/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:34 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:45:48 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}


Fixed::Fixed(const int n)
{
	this->_value = n << _fractionalBits;
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	this->_value = static_cast<int>(roundf(n * (1 << _fractionalBits)));
	//std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &other)
{
	*this = other;
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() 
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) 
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
		this->_value = other.getRawBits(); 
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return(float(this->_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return(this->_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const 
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const 
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const 
{
	return this->getRawBits() >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const 
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const 
{
	return this->getRawBits() == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const 
{
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed((this->_value + other._value) >> _fractionalBits);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed((this->_value - other._value) >> _fractionalBits);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(((this->_value * other._value) >> _fractionalBits) >> _fractionalBits);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed((this->_value << _fractionalBits) / other._value);
}

// Increment/decrement

Fixed& Fixed::operator++() 
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_value;
	return temp;
}

Fixed& Fixed::operator--() 
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_value;
	return temp;
}

// min and max of two Fixed point numbers

Fixed &Fixed::min(Fixed &first, Fixed &other)
{
	if(first.getRawBits() < other.getRawBits())
		return first;
	return other;
}

Fixed &Fixed::max(Fixed& first, Fixed &other)
{
	if(first.getRawBits() > other.getRawBits())
		return first;
	return other;
}
//read only functions
const Fixed &Fixed::min(const Fixed &first, const Fixed &other)
{
	if(first.getRawBits() < other.getRawBits())
		return first;
	return other;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &other)
{
	if(first.getRawBits() > other.getRawBits())
		return first;
	return other;
}
Fixed Fixed::abs() const 
{
	if (_value < 0) {
		return Fixed(-toFloat());
	}
	return *this;
}