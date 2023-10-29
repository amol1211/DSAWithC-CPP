//GFG problem

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// brute-force approach 

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    // Brute-force approach.
  
    int celebrity(vector<vector<int> >& M, int n) {
        int potentialCelebrity = -1; // Initialize potential celebrity to -1 (no potential celebrity found yet).

        // Step 1: Iterate through each person (indexed by 'i').
        for (int i = 0; i < n; i++) {
            int j;

            // Step 2: For each person 'i', check with all other people 'j'.
            for (j = 0; j < n; j++) {
                // Check if 'i' knows 'j' or 'j' doesn't know 'i'.
                if (i != j && (M[i][j] == 1 || M[j][i] == 0)) {
                    break; // If either condition is met, break the inner loop.
                }
            }

            // Step 3: If 'j' reached 'n' without breaking, 'i' could be a potential celebrity.
            if (j == n) {
                potentialCelebrity = i;
            }
        }

        // Step 4: After the outer loop, if potentialCelebrity is still -1, there is no celebrity.
        if (potentialCelebrity == -1) {
            return -1; // No celebrity found.
        }

        // Verify the potential celebrity.
        for (int i = 0; i < n; i++) {
            // Check if the potential celebrity does not know anyone and everyone knows the potential celebrity.
            if (i != potentialCelebrity && (M[potentialCelebrity][i] == 1 || M[i][potentialCelebrity] == 0)) {
                return -1; // The potential celebrity is not a celebrity.
            }
        }

        return potentialCelebrity; // Return the potential celebrity.
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
/*M = [
    [0, 1, 0],
    [0, 0, 0],
    [0, 1, 0]
]
Initialize potentialCelebrity as -1.

For person 0 (i = 0):

Check person 0 with all others (j = 1, 2).
Person 0 knows person 1, which breaks the loop.
For person 1 (i = 1):

Check person 1 with all others (j = 0, 2).
Person 1 doesn't know person 0, and person 0 doesn't know person 1, so continue checking.
Person 1 doesn't know person 2, and person 2 doesn't know person 1, so continue checking.
Person 1 has no exclusions, so it is considered a potential celebrity.
For person 2 (i = 2):

Check person 2 with all others (j = 0, 1).
Person 2 doesn't know person 0, and person 0 doesn't know person 2, so continue checking.
Person 2 doesn't know person 1, and person 1 doesn't know person 2, so continue checking.
Person 2 doesn't have any exclusions, so it is considered a potential celebrity.
After the loops, potentialCelebrity is set to 1 because person 1 was the only one who 
wasn't excluded in all comparisons.

Verify the potential celebrity:

Person 1 doesn't know anyone (rawCheck is true).
Everyone knows person 1 (columnCheck is true).
Therefore, person 1 is the potential celebrity, and the function returns 1 as the celebrity index.*/
/*---------------------------------------------------------------------------------*/

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

//Stack approach 2

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