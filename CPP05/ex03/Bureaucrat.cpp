/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:52:21 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/25 10:38:13 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {
	//std::cout << "Bureaucrat default constructor called." << std::endl;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {
	//std::cout << "Bureaucrat copy constructor called." << std::endl;
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
	if (_grade <= 1) throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrement() {
	if (_grade >= 150) throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout	<< _name
					<< " couldn't sign " << f.getName()
					<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& f) {
	try {
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
