#include <iostream>
using namespace std;

class Solution {
    public:
    void printNos(int N) {
        if (N > 1) {
            printNos(N - 1);
        }
        cout << N << " ";
    }
};