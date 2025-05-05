/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:21:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 19:16:48 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	// ScavTrap st("SC4V-TP");
	// st.attack("enemy");
	// st.takeDamage(20);
	// st.beRepaired(10);
	// st.guardGate();
	
	// FragTrap ft("FR4G-TP");
    // ft.attack("enemy");
    // ft.takeDamage(30);
    // ft.beRepaired(20);
    // ft.highFivesGuys();
    // return 0;

	DiamondTrap dt("Shiny");
    dt.attack("target");
    dt.whoAmI();
    dt.guardGate();
    dt.highFivesGuys();
    return 0;
}