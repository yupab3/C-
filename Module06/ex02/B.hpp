#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base
{
public:
	B();
	virtual ~B();
private:
	B(const B& _copy);
	B& operator=(const B& _copy);
};

#endif
