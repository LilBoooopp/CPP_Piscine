/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:52:21 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/08 00:52:22 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	//std::cout << "Bureaucrat default constructor called." << std::endl;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	//std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = other;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	//std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	//std::cout << "Bureaucrat destructor called." << std::endl;
}

const std::string&	Bureaucrat::getName() const { return _name; }
int					Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::increment() {
	if (_grade - 1 < 1) throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrement() {
	if (_grade + 1 > 150) throw GradeTooLowException();
	++_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
