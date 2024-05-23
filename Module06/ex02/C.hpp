#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base
{
public:
	C();
	virtual ~C();
private:
	C(const C& _copy);
	C& operator=(const C& _copy);
};

#endif
