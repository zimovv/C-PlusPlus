#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec={10,50,101,30,200};
	
	auto isGreaterThan100 = [](auto i){return i>100;};
	
	
	auto intIter = find_if(vec.begin(),vec.end(),isGreaterThan100);
	cout<<"Found a value > 100:"<<*intIter<<endl;
	
	while(intIter!=vec.end()-1)
	{
		intIter = find_if(intIter+1,vec.end(),isGreaterThan100);
		cout<<"Found a value > 100:"<<*intIter<<endl;
	}
		
	
}
