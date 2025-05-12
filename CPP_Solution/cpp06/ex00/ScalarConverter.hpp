/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:59:10 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/10 11:42:41 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& obj);
        ScalarConverter& operator=(ScalarConverter const& rhs);
        ~ScalarConverter();
            
    public:
        static void convert(std::string const& input);
};

#endif