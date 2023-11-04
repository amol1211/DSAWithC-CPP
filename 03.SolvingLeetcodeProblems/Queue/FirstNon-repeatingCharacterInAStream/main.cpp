//GFG Problem
//First non-repeating character in a stream

#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string A){
            
            // Create an unordered map to store character counts.
            unordered_map<char, int> count;
            
            // Create a queue to maintain the order of characters.
            queue<int> q;
            
            // Initialize an empty string to store the answer.
            string ans = "";

            // Loop through the characters in the input string 'A'.
            for (int i = 0; i < A.length(); i++) {
                char ch = A[i];
                
                // Increase the count for the current character.
                count[ch]++;
                
                // Add the current character to the end of the queue.
                q.push(ch);
                
                // Check the characters in the queue for non-repeating characters.
                while (!q.empty()) {
                    if (count[q.front()] > 1) {
                        // If the character at the front of the queue repeats, pop it.
                        q.pop();
                    }
                    else {
                        // If it's the first non-repeating character, append it to 'ans' and break the loop.
                        ans.push_back(q.front());
                        break;
                    }
                }
                if (q.empty()) {
                    // If the queue is empty, it means no non-repeating characters were found so 
                    //far, so add '#' to 'ans'.
                    ans.push_back('#');
                }
            }
            
            // Return the final answer.
            return ans;
        }
};

/*The time complexity of this code is O(N), where N is the length of the input 
string 'A'. This is because the code iterates through each character of the string 
once, and the while loop inside the for loop doesn't change the overall linear time complexity.

Exact Space Complexity:

The unordered_map 'count' can potentially store all distinct characters in 
the input string, so its space complexity is O(K), where K is the number of 
distinct characters in 'A'.
The queue 'q' can also potentially store all distinct characters, resulting in 
a space complexity of O(K).
The 'ans' string, in the worst case, stores a character for each character in the 
 string 'A, so its space complexity is O(N).
Therefore, the total space complexity is O(K) + O(K) + O(N), which can be simplified 
to O(K + N).
The exact space complexity is O(K + N), where K is the number of distinct characters 
in the input string and N is the length of the input string.*/