#include<iostream>
#include<stdlib.h>
using namespace std;


void insert(){

   

    int arr[10]={5,6,8,10};
    int n=4;
    int pos=2;
    int val=7;

    for (int  i = pos; i <n-1; i++)
    {
        arr[i]=arr[i+1];
    }
   
    n--;

    cout<<"Array after deletion:\n";
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<"\n";

}


int main(){

    insert();
    
   system("pause");
    return 0;
    
}
