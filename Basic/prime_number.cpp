#include<iostream>
#include<cstdlib> 

using namespace std;

int main(){
  int n;
  bool isprime=true;
  cout<<"Enter a number"<<endl;
  cin>>n;

  for(int i=2;i*i<=n;i++){
    if (n%i==0)
    {
      isprime=false;
      break;
    }
    
  }

  if (isprime==true)
  {
   cout<<"Prime number\n";
  }else{
    cout<<"Not Prime\n";
  }
  
  
    system("pause"); 
    
    return 0;
}
