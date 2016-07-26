#include <iostream>
using namespace std;
int encryption();
int deciphering();

int encryption()
{
  char plaintext[500],ciphertext[500];  //500?
  int k;
  
  cout<<"Please input the plaintext:"<<endl;
  cin>>plaintext;
  cout<<"Please set the key(a integer):"<<endl;
  cin>>k;
  
  plaintext_length=sizeof(plaintext);
  for(i=0;i<pliantext_length;i++)
  {
    ciphertext[i]=plaintext[i]+k;
  }
  cout<<"The ciphertext is \""<<ciphertext<<"\""<<end;
  
  return 0;
}

int deciphering()
{
  char plaintext[500],ciphertext[500];  //500?
  int k;
  
  cout<<"Please input the ciphertext:"<<endl;
  cin>>ciphertext;
  cout<<"Please give the key(a integer):"<<endl;
  cin>>k;
  
  ciphertext_length=sizeof(ciphertext);
  for(i=0;i<ciphertext_length;i++)
  {
    plaintext[i]=ciphertext[i]-k;
  }
  cout<<"The plaintext is \""<<plaintext<<"\""<<endl;
  return 0;
}

int main()
{
  int choice;
  cout<<"1.encryption"<<endl;
  cout<<"2.deciphering"<<endl;
  cout<<"Please enter your choose(1 or 2):"<<endl;
  cin>>choice;
  if(choice==1)
  {
    encryption();
  }
  else
  {
    deciphering();
  }
  
  return 0;
}
