/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:21:20 by cbopp             #+#    #+#             */
/*   Updated: 2025/05/05 18:52:12 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap st("SC4V-TP");
	st.attack("enemy");
	st.takeDamage(20);
	st.beRepaired(10);
	st.guardGate();
	return 0;
}