#include <iostream>
using namespace std;

class Solution {
    public:
    void printGfg(int N) {
        if (N > 1) {
            printGfg(N - 1);
        }
        cout << "GFG ";
    }
};

