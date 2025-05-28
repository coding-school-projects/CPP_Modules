#pragma once

#include <string> // std::string
#include <stack> // std::stack

class RPN {
private:
    std::string expression;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    static int evaluate(const std::string& expression);
};
