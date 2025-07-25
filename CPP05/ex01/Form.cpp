#include "Form.hpp"

Form::Form(const std::string& name, int sg, int eg)
	: _name(name), _signed(false), _signGrade(sg), _execGrade(eg) {
	//std::cout << "Form default constructor called." << std::endl;
	if (sg < 1 || eg < 1) throw GradeTooHighException();
	if (sg > 150 || eg > 150) throw GradeTooLowException();
}


Form::Form(const Form &other) 
 : _name(other._name), _signed(other._signed) , _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	//std::cout << "Form copy constructor called." << std::endl;
}


Form &Form::operator=(const Form &other)
{
	//std::cout << "Form assignment operator called." << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

Form::~Form(void) {
	//std::cout << "Form destructor called." << std::endl;
}

const std::string& Form::getName() const {
	return (_name);
}

bool	Form::isSigned() const {
	return (_signed);
}

int	Form::getSignGrade() const { return (_signGrade); }
int Form::getExecGrade() const { return (_execGrade); }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form " << f.getName()
		<< " [signed=" << (f.isSigned()? "yes" : "no")
		<< ", signG=" << f.getSignGrade()
		<< ", execG=" << f.getExecGrade() << "]";
	return (os);
}
