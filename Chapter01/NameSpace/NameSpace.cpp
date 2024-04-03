#include <iostream>

namespace	BestComImp1
{
	namespace	BestComImp2
	{
		namespace	BestComImp3
		{
			void	SimpleFunc(void);
			void	PrettyFunc(void);
		}
	}
}

namespace	ProgComImp1
{
	void	SimpleFunc(void);
}

int	value = 0;

int main(void)
{
	int value = 1;
	BestComImp1::BestComImp2::BestComImp3::SimpleFunc();
	std::cout << "\nnamespace를 통합한 뒤 출력하면 아래와 같다.\n\n";
	namespace	BestComImp123 = BestComImp1::BestComImp2::BestComImp3;
	BestComImp123::SimpleFunc();
	std::cout << "\n전역 변수 value 호출 : " << ::value << ", 지역 변수 value 호출 : " << value << "\n";
	return (0);
}

void	BestComImp1::BestComImp2::BestComImp3::SimpleFunc(void)
{
	std::cout << "BestCom이 정의한  함수" << std::endl;
	PrettyFunc();	//동일한 namespace에 선언한 함수
	ProgComImp1::SimpleFunc();	//다른 namespace에 선언한 함수
}

void	BestComImp1::BestComImp2::BestComImp3::PrettyFunc(void)
{
	std::cout << "So Pretty!!" << std::endl;
}

void	ProgComImp1::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의한  함수" << std::endl;
}
