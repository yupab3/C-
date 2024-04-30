#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):ClapTrap("unusing constructor"), ScavTrap("unusing constructor"), FragTrap("unusing constructor"){};

DiamondTrap::DiamondTrap(const std::string &_Name)
	: ClapTrap(_Name + "_clap_name"), ScavTrap(_Name + "_clap_name"), FragTrap(_Name + "_clap_name"){
	std::cout << "DiamondTrap 생성자 호출\n";
	Name = _Name;
	EnergyPoint = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_DiamondTrap)
	: ClapTrap(_DiamondTrap.ClapTrap::Name)
	, ScavTrap(_DiamondTrap.ClapTrap::Name)
	, FragTrap(_DiamondTrap.ClapTrap::Name){
	std::cout << "DiamondTrap 복사 생성자 호출\n";
	Name = _DiamondTrap.Name;
	HitPoint = _DiamondTrap.HitPoint;
	EnergyPoint = _DiamondTrap.EnergyPoint;
	AttackDamage = _DiamondTrap.AttackDamage;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &_DiamondTrap){
	if (this == &_DiamondTrap){
		return *this;
	}
	std::cout << "DiamondTrap 대입 연산자 오버로딩\n";
	Name = _DiamondTrap.Name;
	this->ClapTrap::Name = _DiamondTrap.ClapTrap::Name;
	HitPoint = _DiamondTrap.HitPoint;
	EnergyPoint = _DiamondTrap.EnergyPoint;
	AttackDamage = _DiamondTrap.AttackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap 소멸자 호출\n";
}

void	DiamondTrap::whoAmI(void) const{
	std::cout << "DiamondTrap에 있는 제 이름은 " << Name << "이고, ClapTrap에 있는 제 이름은 " << ClapTrap::Name << "입니다.\n";
}