/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:44:12 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/12 16:31:33 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>

class Array
{
    private:
        T* _data;
        unsigned int _length;

    public:
        Array() : _data(nullptr), _length(0) {}

        Array(unsigned int n) : _length(n)
        {
            if (_length == 0)
				_data = nullptr;
			else
			{
				_data = new T[_length];
				for (unsigned int i = 0; i < _length; ++i)
					_data[i] = T();
			}
        }

        Array(const Array& other) : _length(other._length)
        {
            if (_length == 0)
				_data = nullptr;
			else
			{
				T* tempData = new T[_length];
				try
				{
					for (unsigned int i = 0; i < _length; ++i)
						tempData[i] = other._data[i];
					_data = tempData;
				}
				catch (...)
				{
					delete[] tempData;
					_data = nullptr;
					throw ;
				}
			}
        }

        Array& operator=(const Array& other)
        {
            if (this == &other)
				return *this;
			_length = other._length;
			if (_length == 0)
			{
				delete[] _data;
				_data = nullptr;
			}
			else
			{
				T* tempData = new T[_length];
				try
				{
					for (unsigned int i = 0; i < _length; ++i)
						tempData[i] = other._data[i];
					delete[] _data;
					_data = tempData;
				}
				catch (...)
				{
					delete[] tempData;
					throw ;
				}
			}
			return *this;
        } 
 
        ~Array()
        {
            delete[] _data;
        }

        T& operator[](unsigned int index)
        {
            if (index < 0 || static_cast<unsigned int>(index) >= _length)
				throw std::out_of_range("Array::operator[] error: index out of bounds");
			return _data[index];
        }

        // Const version for read-only access
        const T& operator[](unsigned int index) const
        {
            if (index < 0 || static_cast<unsigned int>(index) >= _length)
				throw std::out_of_range("Array::operator[] error: index out of bounds");
			return _data[index];
        }

        unsigned int size() const
        {
            return _length;
        }
};
