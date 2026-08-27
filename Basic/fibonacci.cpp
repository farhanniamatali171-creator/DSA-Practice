#include <iostream>
using namespace std;


int fibonacci(int n) {

    for (int i = 0; i <= n; i++)
    {
       if (n<=1)
       {
       return 0;
       }
       if (n<=2)
       {
        return 1;
       }
       return fibonacci(n-1)+fibonacci(n-2);
       
       
    }
    
}
void printFibonacci(int n){
    cout<<"Fibonacci Series:\n"; 
    for (int i = 0; i <= n; i++)
    {
        cout<<fibonacci(i)<<endl;
    }
    
}



int main() {
 
    int n=10;
    printFibonacci(n);

    system("pause");
    return 0;
}
