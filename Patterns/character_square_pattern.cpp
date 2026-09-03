#include<iostream>
#include<cstdlib> 

using namespace std;

int main(){
  
int n=4;
int m= 4;
  for (int i = 0; i < n; i++)
  {
    char ch='A';
    for (int j = 0; j <m; j++)
    {
    cout<< ch;
    ch+=1;
    }
    cout<<endl;
    
  }
  
    system("pause"); 
    
    return 0;
}
/*
Output:
ABCD
ABCD
ABCD
ABCD
*/
