#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n = 4;
    int m = 3;
    // char ch = 'A';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
            // cout << ch;
        }
        // ch += 1;
        cout << endl;
    }

    system("pause");

    return 0;
}
