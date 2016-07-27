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
    if('a'<=plaintext[i]<='z')
    {
        ciphertext[i]='a'+(plaintext[i]-'a'+k)%26;
    }
    else if('A'<=plaintext[i]<='Z')
    {
      
      ciphertext[i]='A'+(plaintext[i]-'A'+k)%26;
    }
    else  //if palintext contains not only English letters.
    {
      ciphertext[i]=plaintext[i]+k;
    }
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
    if('a'<=ciphertext<='z')
    {
      plaintext[i]='a'+(ciphertext[i]-'a'-k+26)%26;
    }
    else if('A'<=ciphertext<='Z')
    {
      plaintext[i]='A'+(ciphertext[i]-'a'-k+26)%26;
    }
    else  //if not english letters
    {
      plaintext[i]=ciphertext[i]-k;
    }
    
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
