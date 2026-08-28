// PYRAMID PATTERN

#include<iostream>
#include<cstdlib> 

using namespace std;

int main(){
  
int n=4;
  int m= 3;
  


  for (int i = 0; i <=n ; i++)
  {
    //Spaces:n-i-1
    for (int j = 0; j <n-i-1; j++)
    {
      cout<< " ";
    
    }
    //Num1:i+1
     for (int j= 1;j<=i+i ; j++)
      {
        cout<< j;
        
      }
      //Num2:
      for (int j= 1;j>=1 ; j--)
      {
        cout<< j;
        
      }
    
    cout<<endl;
    
  }
  
  
    system("pause"); 
    
    return 0;
}
