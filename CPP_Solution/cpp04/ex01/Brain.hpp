/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:31:37 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:24:53 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string _ideas[100];
        
    public:
        // Orthodox Canonical Form
		Brain();                               
		Brain(const Brain& other);			  
		Brain& operator = (const Brain& src);   
		~Brain();

        void setIdea(int index, const std::string& idea);  // Set an idea
		std::string getIdea(int index) const;  // Get an idea
};

#endif
