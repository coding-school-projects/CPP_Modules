/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:11 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:18:13 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
		static bool isOperator(char c);
    	static int performOperation(char op, int a, int b);
		
	public:
        RPN();
    	RPN(const RPN& other);
    	RPN& operator=(const RPN& other);
    	~RPN();
		
        static int evaluate(const std::string& expression);
};
#endif