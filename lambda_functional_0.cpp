#include<iostream>
#include<functional>
using namespace std;

function<int(void)> add10(int x){return [x]{return x+10;};}

int main()
{
	function<int(void)>fn = add10(5);
	
	cout<<"fn="<<fn()<<endl;
}
