/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:20 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 13:44:39 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {}
    return *this;
}

void PmergeMe::sortAndDisplay(const std::vector<int>& input)
{
    if (input.empty()) return;

    displaySequence("Before:", input);

    std::vector<int> vec(input.begin(), input.end());
    std::deque<int> deq(input.begin(), input.end());

    clock_t startVec = clock();
    fordJohnsonSort(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    fordJohnsonSort(deq);
    clock_t endDeq = clock();

    displaySequence("After:", vec);
    displayTime(startVec, endVec, vec.size(), "std::vector");
    displayTime(startDeq, endDeq, deq.size(), "std::deque");
}

/* ===
fordJohnsonSort using vector and deque
mergeInsertsort
    1.Pairing elements
    2.Sort pairs by their second elements (simple insertion sort style)
    3.Create sortedBigNbrsList and smallerNbrsList from sorted pairs
    4.If odd size, add last unpaired element
InsertUsingBinarySearch
    5.Insert smallerNbrsList elements into sortedBigNbrsList using binary search
    6.Assign sorted result back to original deque/vector
=== */

// Vector implementations
void PmergeMe::fordJohnsonSort(std::vector<int>& vec)
{
    if (vec.size() <= 1) return;

    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].second > pairs[j].second) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }

    std::vector<int> sortedBigNbrsList;
    std::vector<int> smallerNbrsList;
    for (size_t i = 0; i < pairs.size(); ++i) {
        sortedBigNbrsList.push_back(pairs[i].second);
        smallerNbrsList.push_back(pairs[i].first);
    }

    if (vec.size() % 2 != 0) {
        smallerNbrsList.push_back(vec.back());
    }

    for (size_t i = 0; i < smallerNbrsList.size(); ++i) {
        std::vector<int>::iterator it = std::lower_bound(sortedBigNbrsList.begin(), sortedBigNbrsList.end(), smallerNbrsList[i]);
        sortedBigNbrsList.insert(it, smallerNbrsList[i]);
    }
    vec = sortedBigNbrsList;
}

// Deque implementations
void PmergeMe::fordJohnsonSort(std::deque<int>& deq)
{
    if (deq.size() <= 1) return;

    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        if (deq[i] < deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].second > pairs[j].second) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }

    std::deque<int> sortedBigNbrsList;
    std::deque<int> smallerNbrsList;
    for (const auto& p : pairs) {
        sortedBigNbrsList.push_back(p.second);
        smallerNbrsList.push_back(p.first);
    }

    if (deq.size() % 2 != 0) {
        smallerNbrsList.push_back(deq.back());
    }

    for (int val : smallerNbrsList) {
        auto it = std::lower_bound(sortedBigNbrsList.begin(), sortedBigNbrsList.end(), val);
        sortedBigNbrsList.insert(it, val);
    }
    deq = sortedBigNbrsList;
}

void PmergeMe::displaySequence(const std::string& prefix, const std::vector<int>& seq)
{
    std::cout << prefix;
    for (size_t i = 0; i < seq.size(); ++i) {
        std::cout << " " << seq[i];
    }
    std::cout << std::endl;
}

void PmergeMe::displayTime(clock_t start, clock_t end, size_t count, const std::string& containerType)
{
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << count 
              << " elements with " << containerType << ": " 
              << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
}