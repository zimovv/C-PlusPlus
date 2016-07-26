#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int original_num,inverted_num,tmp_num;
  int a[5];
  
  cout<<"Input a five-digit number:"
  cin>>original_num;
  
  for(i=0;i<5;i++)
  {
    a[i]=(original_num/pow(10,i))%10;
  }
  
  tmp_num=0;
  for(i=0;i<5;i++)
  {
    tmp_num=tmp_num*10+a[i];
  }
  inverted_num=tmp_num;
  
  cout<<original_num<<"is inverted to "<<inverted_num<<endl;
  
  return 0;
}
