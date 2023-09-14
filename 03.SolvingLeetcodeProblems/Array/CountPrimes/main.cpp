#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count;        
    }
};

/*-------------------------------------------------------------*/
class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> arr(n+1, true);
    
    // for count of prime nos
    int count=0;
    
    // Starting from  2 because 1 is neither prime nor composite
    for(int i=2;i<n;i++)
    {
        // if its true that is prime then make all multiples of it as true
        if(arr[i])
        {
            count++;
            
            for(int j=2*i;j<n;j+=i)
                arr[j]=false;
        }
    }
    
    return count; 
    }
};