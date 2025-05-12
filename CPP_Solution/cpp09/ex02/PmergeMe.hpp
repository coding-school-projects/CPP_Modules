/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:22 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 13:44:44 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>

class PmergeMe
{
    private:
        void fordJohnsonSort(std::vector<int>& vec); // Vector
        void fordJohnsonSort(std::deque<int>& deq);  // Deque
    
        void displaySequence(const std::string& prefix, const std::vector<int>& seq);
        void displayTime(clock_t start, clock_t end, size_t count, const std::string& containerType);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& other);

        void sortAndDisplay(const std::vector<int>& input);
};

#endif