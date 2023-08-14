#include <iostream>
using namespace std;

class Solution {
    public:
    void printNos(int N)
{
    // base case: if N is 0, return
    if (N == 0) {
        return;
    }
 
    // print N
    cout << N << " ";
 
    // recursively call printNos to print N-1, N-2, N-3, ..., 2, 1
    printNos(N - 1);
}

};