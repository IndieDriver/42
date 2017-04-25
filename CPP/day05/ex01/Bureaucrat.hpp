#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		virtual ~Bureaucrat(void);
		Bureaucrat & operator=(Bureaucrat const & rhs);

		void		incGrade();
		void		decGrade();

		void		signForm(Form *form);

		std::string getName() const;
		int			getGrade() const;

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
		Bureaucrat(void);
		const std::string 	_name;
		int					_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &i);

#endif
