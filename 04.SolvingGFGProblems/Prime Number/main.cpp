#include <iostream>
using namespace std;

class Solution{
public:
    int isPrime(int N){
        int count = 0;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                count++;
                if ((N/i) != i) count ++;
            }
        }
        if (count == 2) 
        return true;
        else 
        return false;
    }
};

/*--------------------------------------------------*/

class Solution{
public:
    int isPrime(int N){
        if ( N < 2) {
            return 0;
        }
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                return 0;
            }
        }
        return 1;
    }
};