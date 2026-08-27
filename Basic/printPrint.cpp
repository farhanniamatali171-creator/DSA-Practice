#include <iostream>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false; 
    

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true; 
}


void printPrimes(int n) {
    cout << "Primes from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    printPrimes(31);
    system("pause");
    return 0;
}
