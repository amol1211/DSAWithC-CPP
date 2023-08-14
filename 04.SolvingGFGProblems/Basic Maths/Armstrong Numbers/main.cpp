#include <iostream>
using namespace std;

class Solution {
  public:
    string armstrongNumber(int n){
        
        int dup = n;
        int sum = 0;
        
        while (n > 0) {
            int ld = n % 10;
            sum += (ld * ld * ld);
            n /= 10;
        }
        if (dup == sum)
        return "Yes";
        else
        return "No";
    }
};