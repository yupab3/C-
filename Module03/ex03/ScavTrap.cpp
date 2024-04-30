#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("unusing constructor"){};

ScavTrap::ScavTrap(const std::string &_Name) : ClapTrap(_Name){
	std::cout << "ScavTrap 생성자 호출\n";
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &_ScavTrap) : ClapTrap(_ScavTrap.Name){
	std::cout << "ScavTrap 복사 생성자 호출\n";
	HitPoint = _ScavTrap.HitPoint;
	EnergyPoint = _ScavTrap.EnergyPoint;
	AttackDamage = _ScavTrap.AttackDamage;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &_ScavTrap){
	if (this == &_ScavTrap){
		return *this;
	}
	std::cout << "ScavTrap 대입 연산자 오버로딩\n";
	Name = _ScavTrap.Name;
	HitPoint = _ScavTrap.HitPoint;
	EnergyPoint = _ScavTrap.EnergyPoint;
	AttackDamage = _ScavTrap.AttackDamage;
	return *this;
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap \"" << Name << "\"은(는) 문지기 모드로 변경했다!!\n";
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap 소멸자 호출\n";
}

void	ScavTrap::attack(const std::string &target){
	if (EnergyPoint > 0 && HitPoint > 0){
		std::cout << "ScavTrap \"" << Name << "\"은(는) \"" << target << "\"에게 " << AttackDamage << "의 피해를 입혔다!!\n";
		EnergyPoint--;
		std::cout << "ScavTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
	else{
		std::cout << "ScavTrap \"" << Name << "\"은(는) 아무것도 할 수 없다..\n";
		std::cout << "ScavTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
}
