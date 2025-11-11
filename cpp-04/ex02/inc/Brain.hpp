#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();

		std::string	getIdea(int n) const;
		void	setIdea(std::string idea, int n);
};

#endif