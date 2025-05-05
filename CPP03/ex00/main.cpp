/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:21:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 18:38:06 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Jack");

    a.attack("Target Dummy");
    a.takeDamage(4);
    a.beRepaired(2);
    a.takeDamage(10);
    a.attack("Another Dummy");
    a.beRepaired(5);

    return 0;
}