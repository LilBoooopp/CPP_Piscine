#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}

AForm::AForm(const std::string& name, int sg, int eg)
	: _name(name), _signed(false), _signGrade(sg), _execGrade(eg) {
	//std::cout << "Form default constructor called." << std::endl;
	if (sg < 1 || eg < 1) throw GradeTooHighException();
	if (sg > 150 || eg > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed) , _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	//std::cout << "Form copy constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	//std::cout << "Form assignment operator called." << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm(void) {
	//std::cout << "Form destructor called." << std::endl;
}

const std::string&	AForm::getName() const { return (_name); }
bool				AForm::isSigned() const { return (_signed); }
int					AForm::getSignGrade() const { return (_signGrade); }
int					AForm::getExecGrade() const { return (_execGrade); }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& exec) const {
	if (!_signed) throw NotSignedException();
	if (exec.getGrade() > _execGrade) throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form " << f.getName()
		<< " [signed=" << (f.isSigned()? "yes" : "no")
		<< ", signG=" << f.getSignGrade()
		<< ", execG=" << f.getExecGrade() << "]";
	return (os);
}
