#include "Harl.hpp"

void	Harl::debug(void){
	std::cout << "I need more RAM to improve the performance of my computer.\n";
}

void	Harl::info(void){
	std::cout << "The total cost of buying more RAM is 2,000 dollars.\n";
}

void	Harl::warning(void){
	std::cout << "If you want to survive, please pay for me to buy the ram instead.\n";
}

void	Harl::error(void){
	std::cout << "Shut up and give me the money now!!\n";
}

void	Harl::complain(std::string level){
	int	idx;
	for (idx = 0; idx < 4; idx++){
		if (level == TrgtStr[idx]) break;
	}
	if (idx < 4) (this->*Func[idx])();
}

Harl::Harl(void){
	Func[0] = &Harl::debug;
	Func[1] = &Harl::info;
	Func[2] = &Harl::warning;
	Func[3] = &Harl::error;
	TrgtStr[0] = "DEBUG";
	TrgtStr[1] = "INFO";
	TrgtStr[2] = "WARNING";
	TrgtStr[3] = "COMPLAIN";
}
