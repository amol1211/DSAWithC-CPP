//1601. Maximum Number of Achievable Transfer Requests

#include <iostream>
#include <climits>
#include <vector>
using namespace std;


class Solution {
public:
    // Variable to store the number of requests
    int m;
    
    // Variable to store the maximum result
    int result = INT_MIN;
    
    // Recursive function to explore all possibilities of making requests
    void solve(int index, int count, int n, vector<int>& resultant, vector<vector<int>>& requests) {
        // Base case: if all requests are processed
        if(index >= m) {
            // Check if the resultant vector has all zero elements
            int allZero = true;
            for(int &x : resultant) {
                if(x != 0) {
                    allZero = false;
                    break;
                }
            }
            
            // If all elements are zero, update the result with the maximum count
            if(allZero) {
                result = max(result, count);
            }
            return;
        }
        
        // Extract 'from' and 'to' indices from the current request
        int from = requests[index][0];
        int to   = requests[index][1];
        
        // Make a request: decrease count in 'from', increase count in 'to', and explore
        resultant[from]--;
        resultant[to]++;
        solve(index+1, count+1, n, resultant, requests);
        
        // Backtrack: undo the request and explore without making it
        resultant[from]++;
        resultant[to]--;
        solve(index+1, count, n, resultant, requests);
    }
    
    // Main function to find the maximum number of requests
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // Set the number of requests
        m = requests.size();
        
        // Vector to represent the current state of the system after processing requests
        vector<int> resultant(n, 0);
        
        // Start the recursive backtracking process
        solve(0, 0, n, resultant, requests);
        
        // Return the final result
        return result;
    }
};

//Time complexity : O(2^m), where m is the number of requests.
//Space complexity : O(n) 