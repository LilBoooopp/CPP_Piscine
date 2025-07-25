/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:52:25 by cbopp             #+#    #+#             */
/*   Updated: 2025/07/25 10:35:12 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what () const throw();
		};
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string&	getName() const;
		int					getGrade() const;

		void	increment();
		void	decrement();

		void	signForm(AForm& f) const;
		void	executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
