#include <iostream>
using namespace std;

void pattern6(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            cout << n - j + 1 << " ";
        }

        cout << endl;
    }
}

int main () {

    int n = 5;

    pattern6(n);

    return 0;
}

/*--------------------------------------------------*/

#include <iostream>
using namespace std;

void pattern6(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            cout << n - j + 1 << " ";
        }

        cout << endl;
    }
}

int main () {

    int n = 5;

    pattern6(n);

    return 0;
}