/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:20:47 by cbopp             #+#    #+#             */
/*   Updated: 2025/08/19 14:30:54 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain(void);
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain(void);

        std::string	ideas[100];
};

#endif
