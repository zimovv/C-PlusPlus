#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec={1,4,2,5};
	
	for(auto it=begin(vec);it<end(vec)-1;it++)
	{
		it = find_if(it,end(vec),bind(greater_equal<>(),placeholders::_1,3));
		cout<<"Found a int >2:"<<*it<<endl;
	}
	/*
	auto it=find_if(begin(vec),end(vec),bind(greater_equal<>(),placeholders::_1,3));
	
	while(it!=end(vec))
	{
		cout<<"Found a int >2:"<<*it<<endl;
		it=find_if(it+1,end(vec),bind(greater_equal<>(),placeholders::_1,3));
		
	}*/
		
}
