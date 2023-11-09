//402. Remove K Digits

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 1.Stack approach

class Solution {
public:
    string removeKdigits(string num, int k) {
        // number of operation greater than length we return an empty string
        if(num.length() <= k)   
            return "0";
        
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0)
            return num;
        
        string res = "";// result string
        stack <char> s; // char stack
        
        s.push(num[0]); // pushing first character into stack
        
        for(int i = 1; i<num.length(); ++i) {
            while(k > 0 && !s.empty() && num[i] < s.top()) {
                // if k greater than 0 and our stack is not empty and the upcoming digit,
                // is less than the current top than we will pop the stack top
                --k;
                s.pop();
            }
            
            s.push(num[i]);
            
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        while(k && !s.empty()) {
            // for cases like "456" where every num[i] > num.top()
            --k;
            s.pop();
        }
        
        while(!s.empty()) {
            res.push_back(s.top()); // pushing stack top to string
            s.pop(); // pop the top element
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0)
            return "0";
        
        return res;     
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*-------------------------------------------------------------------------------*/

// 2. Brute force approach(TLE)

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.length();

    // Base case: if k is greater than or equal to the length of the number, return "0"
    if (k >= n)
        return "0";

    string smallest = num;

    // Generate all combinations of removing k digits
    for (int i = 0; i < k; ++i) {
        size_t j = 0;
        while (j < smallest.length() - 1 && smallest[j] <= smallest[j + 1]) {
            ++j;
        }

        // Remove the digit at index j
        smallest.erase(smallest.begin() + j);
    }

    // Remove leading zeroes
    size_t nonZeroIndex = smallest.find_first_not_of('0');
    smallest = (nonZeroIndex != string::npos) ? smallest.substr(nonZeroIndex) : "0";

    return smallest;
    }
};

//Time complexity : O(k * n^2)
//Space complexity : O(n)
