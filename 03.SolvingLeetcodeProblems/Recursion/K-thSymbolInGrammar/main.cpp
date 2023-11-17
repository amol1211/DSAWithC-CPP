#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the Kth grammar symbol in the Nth row of the grammar sequence
    int kthGrammar(int N, int K) {
        // Base case: when N is 1 and K is 1, return 0 (first symbol in the sequence)
        if (N == 1 && K == 1)
            return 0;

        // Calculate the midpoint of the sequence for the current row
        int mid = pow(2, N - 1) / 2;

        // If K is less than or equal to the midpoint, recurse on the left half
        if (K <= mid)
            return kthGrammar(N - 1, K);

        // If K is greater than the midpoint, recurse on the right half
        // and negate the result (!) as the pattern alternates between 0 and 1
        return !kthGrammar(N - 1, K - mid);
    }
};

//Time complexity: O(2^N)
//Space complexity: O(N)