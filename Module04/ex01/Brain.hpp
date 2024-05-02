#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
public:
	std::string ideas[100];
public:
	Brain(void);
	Brain(const Brain &_Brain);
	Brain&	operator=(const Brain &_Brain);
	virtual ~Brain(void);
};

#endif
