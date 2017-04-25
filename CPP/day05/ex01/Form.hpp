#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(Form const & src);
		Form(std::string name, int signGrade, int execGrade);
		virtual ~Form(void);
		Form & operator=(Form const & rhs);

		void				beSigned(Bureaucrat *bureaucrat);

		std::string			getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & src);
				virtual ~GradeTooLowException(void) throw();
				GradeTooLowException & operator=(GradeTooLowException const & rhs);
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & src);
				virtual ~GradeTooHighException(void) throw();
				GradeTooHighException & operator=(GradeTooHighException const & rhs);
				virtual const char* what() const throw();
		};

	private:
		const std::string 	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & i);

#endif
