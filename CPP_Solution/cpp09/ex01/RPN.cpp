/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:08 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:58:21 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int a, int b)
{
    switch (op) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/': 
            if (a == 0) throw std::runtime_error("Division by zero");
            return b / a;
        default: throw std::runtime_error("Invalid operator");
    }
}

int RPN::evaluate(const std::string& expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);  // Create stream from the expression string
    std::string token;  // Variable to store each token

    while (iss >> token) {   // Extract next token until end
        if (token.length() == 1) {
            char c = token[0];
            if (isdigit(c)) {
                stack.push(c - '0');
            } 
			else if (isOperator(c)) {
                if (stack.size() < 2) {
                    throw std::runtime_error("Not enough operands for operator");
                }
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(performOperation(c, a, b));
            }
			else {
                throw std::runtime_error("Invalid token");
            }
        } else {
            throw std::runtime_error("Invalid token");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression - too many operands");
    }
    return stack.top();
}