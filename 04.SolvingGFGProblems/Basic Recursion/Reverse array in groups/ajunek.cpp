#include <iostream>
using namespace std;

Class Solution {
    public:
    void reverseInGroups(vector<long long>& arr, int N, int K) {
    for (int i = 0; i < N; i+=K) {
        int left = i;
        int right = min(i + K - 1, n - 1);

        while (left < right) {
            swap (arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
};

/*------------------------------------------------------------------*/

