#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int original_num,inverted_num,tmp_num;
  int a[10]; //Size of max integer(unsigned int) is 10.
  int original_num_length;
  
  cout<<"Input a five-digit number:"
  cin>>original_num;
  
  original_num_length=sizeof(original_num);
  for(i=0;i<original_num_length;i++)
  {
    a[i]=(original_num/pow(10,i))%10;
  }
  
  tmp_num=0;
  for(i=0;i<original_num_length;i++)
  {
    tmp_num=tmp_num*10+a[i];
  }
  inverted_num=tmp_num;
  
  if(original_num==inverted_num)
    cout<<original_num<<" is a palindromic number!"<<endl;
  else
    cout<<original_num<<" is inverted to "<<inverted_num<<endl;
  
  return 0;
}
