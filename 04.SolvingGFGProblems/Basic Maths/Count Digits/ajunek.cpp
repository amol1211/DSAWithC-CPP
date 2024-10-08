#include <iostream>
using namespace std;

int evenlyDivides(int n) {

    int count = 0;
    int num = n;

    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        num /= 10;
    }

    return count;
}