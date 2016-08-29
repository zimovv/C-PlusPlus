/*NOK*/

#include <iostream>
#include <vector>
using namespace std;

class Base
{
	public:
	Base()=default;
	Base(int):Base(int,""){};  //Delegation constructor
	Base(int, string){};
	Base(Base &&){};
	virtual print(){cout<<"m_a="<<m_a<<endl;cout<<"m_str="<<m_str<<endl;};
	
	private:
	int m_a;
	int m_str;
};

Base::Base(Base &&obj)
{
	
}

class Derived:class Base
{
	public:
	Derived()=default;
	virtual print(int a){cout<<"Derived a="<<a<<endl;}override;
	
private:
	int *ptrInt =new int;
};

int main()
{
	vector<A> vec;
	A objA1(10);
	vec.push_back(objA1);
	A objA2(10,"world");
	vec.push_back(objA2);
	A objA3(objA1);
	
}
