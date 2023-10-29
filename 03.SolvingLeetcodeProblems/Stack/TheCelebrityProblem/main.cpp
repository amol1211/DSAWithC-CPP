//GFG problem

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Stack approach 1

class Solution 
{
private: 
    // Helper function to check if a knows b.
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }
    
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> s;
        // Step 1: Push all elements into the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Step 2: Get 2 elements and compare them
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if (knows(M, a, b, n)) {
                s.push(b);
            }
            else {
                s.push(a);
            }
        }
        
        int ans = s.top();
        // Step 3: Single element in the stack could be a potential celebrity, so, we have to verify it.
        bool rawCheck = false;
        int zeroCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        // Checking if all zeroes
        if (zeroCount == n) {
            rawCheck = true;
        }

        // Column check
        bool columnCheck = false;
        int oneCount = 0;

        for (int i = 0; i < n; i++) {
            if (M[i][ans] == 1) {
                oneCount++;
            }
        }

        if (oneCount == n - 1) {
            columnCheck = true;
        }

        if (rawCheck == true && columnCheck == true) {
            return ans; // The celebrity was found.
        }
        else {
            return -1; // No celebrity was found.
        }
    }
};

/*--------------------------------------------------------------------------*/

class Solution 
{
private: 
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }
    
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> s;
        // Step 1: Push all elements into the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Step 2: Get 2 elements and compare them
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if (knows(M, a, b, n)) {
                s.push(b);
            }
            else {
                s.push(a);
            }
        }
        
        int ans = s.top();
        // Step 3: Single element in the stack could be a potential celebrity, so, we have to verify it.
        
        int zeroCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 0) {
                zeroCount++;
            }
        }
        
        //Checking if all zeroes
        if (zeroCount != n) {
            return -1;
        }

        // Column check
        int oneCount = 0;

        for (int i = 0; i < n; i++) {
            if (M[i][ans] == 1) {
                oneCount++;
            }
        }

        if (oneCount != n - 1) {
            return -1;
        }

        
        return ans;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)