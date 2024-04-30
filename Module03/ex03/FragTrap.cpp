#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("unusing constructor"){};

FragTrap::FragTrap(const std::string &_Name) : ClapTrap(_Name){
	std::cout << "FragTrap 생성자 호출\n";
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &_FragTrap) : ClapTrap(_FragTrap.Name){
	std::cout << "FragTrap 복사 생성자 호출\n";
	HitPoint = _FragTrap.HitPoint;
	EnergyPoint = _FragTrap.EnergyPoint;
	AttackDamage = _FragTrap.AttackDamage;
}

FragTrap&	FragTrap::operator=(const FragTrap &_FragTrap){
	if (this == &_FragTrap){
		return *this;
	}
	std::cout << "FragTrap 대입 연산자 오버로딩\n";
	Name = _FragTrap.Name;
	HitPoint = _FragTrap.HitPoint;
	EnergyPoint = _FragTrap.EnergyPoint;
	AttackDamage = _FragTrap.AttackDamage;
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap \"" << Name << "\"은(는) 하이파이브를 요청했다!!\n";
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap 소멸자 호출\n";
}
