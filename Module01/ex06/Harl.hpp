#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
private:
	std::string	TrgtStr[4];
	void	(Harl::*Func[4])(void);
public:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	complain(std::string level);
	Harl(void);
};

#endif