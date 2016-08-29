#include<iostream>
#include<functional>
using namespace std;

function<int(void)> add(int x,int y){return [x,y]{return x+y;};}

int main()
{
	function<int(void)>fn = add(5,5);
	
	cout<<"fn="<<fn()<<endl;
}
