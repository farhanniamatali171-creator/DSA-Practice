#include<iostream>
#include<stdlib.h>
using namespace std;


void insert(){

    bool found=false;

    int arr[10]={5,6,8,10};
    int n=4;
    int pos=2;
    int val=7;
    for (int  i = n; i >pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    n++;

    cout<<"Array after insertion:\n";
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
