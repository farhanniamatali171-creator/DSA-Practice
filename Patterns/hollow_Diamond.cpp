#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // --- UPPER HALF ---
    for (int i = 0; i < n; i++) {
        // 1.spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        
        // 2. print stars
        for (int k = 0; k < 2 * i + 1; k++) {
            if (k == 0 || k == 2 * i) {
                cout << "*"; // Print boundary stars
            } else {
                cout << " "; // Print hollow space inside
            }
        }
        cout << endl;
    }

    // --- LOWER HALF ---
    for (int i = n - 2; i >= 0; i--) {
        // 1. spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        
        // 2. Print stars and inner spaces
        for (int k = 0; k < 2 * i + 1; k++) {
            if (k == 0 || k == 2 * i) {
                cout << "*"; // Print boundary stars
            } else {
                cout << " "; // Print hollow space inside
            }
        }
        cout << endl;
    }
     system("pause");

    return 0;
}
