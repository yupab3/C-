#include <iostream>
using namespace std;

struct test{
	string	str;
	int		num;

	void	show_data(){
		cout << "num: " << num << ", str: " << str << '\n';
	}
};

class Structure
{
private:
	int a;
public:
	int b;
	void set_a(int _a);
	int	get_a(void);
	Structure(/* args */);
	~Structure();
};

void	Structure::set_a(int _a){
	a = _a;
}

int	Structure::get_a(){
	return a;
}

Structure::Structure(/* args */)
{
}

Structure::~Structure()
{
}

int testtest(Structure _A){
	_A.b = 1;
	_A.set_a(2);
	return 0;
}

int main(){
	Structure A;

	cout << A.b << A.get_a() << '\n';
	testtest(A);
	cout << A.b << A.get_a() << '\n';
}