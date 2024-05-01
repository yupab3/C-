#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){};

ClapTrap::ClapTrap(const std::string &_Name):Name(_Name), HitPoint(10), EnergyPoint(10), AttackDamage(0){
	std::cout << "ClapTrap 생성자 호출\n";
}

ClapTrap::ClapTrap(const ClapTrap &_ClapTrap):Name(_ClapTrap.Name), HitPoint(_ClapTrap.HitPoint), EnergyPoint(_ClapTrap.EnergyPoint), AttackDamage(_ClapTrap.AttackDamage){
	std::cout << "ClapTrap 복사 생성자 호출\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &_ClapTrap){
	if (this == &_ClapTrap){
		return *this;
	}
	std::cout << "ClapTrap 대입 연산자 오버로딩 호출\n";
	Name = _ClapTrap.Name;
	HitPoint = _ClapTrap.HitPoint;
	EnergyPoint = _ClapTrap.EnergyPoint;
	AttackDamage = _ClapTrap.AttackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap 소멸자 호출\n";
}


void	ClapTrap::attack(const std::string &target){
	if (EnergyPoint > 0 && HitPoint > 0){
		std::cout << "ClapTrap \"" << Name << "\"은(는) \"" << target << "\"에게 " << AttackDamage << "의 피해를 입혔다!!\n";
		EnergyPoint--;
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
	else{
		std::cout << "ClapTrap \"" << Name << "\"은(는) 아무것도 할 수 없다..\n";
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (EnergyPoint > 0 && HitPoint > 0){
		std::cout << "ClapTrap \"" << Name << "\"은(는) " << amount << "만큼의 피해를 입었다!!\n";
		HitPoint -= amount;
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
	else{
		std::cout << "ClapTrap \"" << Name << "\"은(는) 아무것도 할 수 없다..\n";
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (EnergyPoint > 0 && HitPoint > 0){
		std::cout << "ClapTrap \"" << Name << "\"은(는) " << amount << "만큼 회복했다!!\n";
		EnergyPoint--;
		HitPoint += amount;
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
	else{
		std::cout << "ClapTrap \"" << Name << "\"은(는) 아무것도 할 수 없다..\n";
		std::cout << "ClapTrap \"" << Name << "\"의 체력: " << HitPoint << ", 에너지: " << EnergyPoint << ", 공격력: " << AttackDamage << '\n';
	}
}

const int&	ClapTrap::getAttackDamage(void) const{
	return (AttackDamage);
}
