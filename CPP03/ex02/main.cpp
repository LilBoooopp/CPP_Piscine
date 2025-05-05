/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:21:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 19:02:28 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	// ScavTrap st("SC4V-TP");
	// st.attack("enemy");
	// st.takeDamage(20);
	// st.beRepaired(10);
	// st.guardGate();
	
	FragTrap ft("FR4G-TP");
    ft.attack("enemy");
    ft.takeDamage(30);
    ft.beRepaired(20);
    ft.highFivesGuys();
    return 0;
}