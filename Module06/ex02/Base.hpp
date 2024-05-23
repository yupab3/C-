#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
public:
	Base();
	virtual ~Base();
private:
	Base(const Base& _copy);
	Base& operator=(const Base& _copy);
};

#endif
