//1209. Remove All Adjacent Duplicates in String II

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//Approach 1: Brute-force
//Just keep removing duplicates until there is no more. When we find a duplicate, 
//we call the same function recursively with that duplicate removed.

string removeDuplicates(string s, int k) {
  for (auto i = 1, cnt = 1; i < s.size(); ++i) {
    if (s[i] != s[i - 1]) cnt = 1;
    else if (++cnt == k)
      return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
  }
  return s;
}

// Or, we can do the same iteratively. It's a bit harder on eyes but easier on memory :)

string removeDuplicates(string s, int k, bool replaced = true) {
  while (replaced) {
    replaced = false;
    for (auto i = 1, cnt = 1; i < s.size() && !replaced; ++i) {
      if (s[i] != s[i - 1]) cnt = 1;
      else if (++cnt == k) {
        s = s.substr(0, i - k + 1) + s.substr(i + 1);
        replaced = true;
      }
    }
  }
  return s;
}


/*Complexity Analysis
Time: O(n * n / k). We scan the entire string for each duplicte we find and remove.
Memory: O(n * n / k) for the recursive approach.
O(1) for the iterative approach.*/

/*--------------------------------------------------------------------------------------*/

//Approach 2: Two pointers

string removeDuplicates(string s, int k) {
  auto j = 0;
  vector<int> cnt(s.size(), 1);
  for (auto i = 0; i < s.size(); ++i, ++j) {
    s[j] = s[i];
    if (j > 0 && s[j] == s[j - 1]) cnt[j] = cnt[j - 1] + 1;
    else cnt[j] = 1;
    if (cnt[j] == k) j -= k;
  }
  return s.substr(0, j);
}

/*Complexity Analysis
Time: O(n). We process each character in the input string once.
Memory: O(n) to track the running count for each character.*/
/*---------------------------------------------------------------------------------------*/

// 3. Stack appraoch

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char, int>> st; // Use a stack of pairs to store characters and their counts

        // Handle special cases
        if (s.length() <= k) {
            return ""; // If the string length is less than or equal to k, return an empty string
        }
        if (k == 0) {
            return s; // If k is 0, return the original string as there's no need to remove any characters
        }

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                // If the stack is not empty and the current character is the same as the character 
                //at the top of the stack
                if (++st.top().second == k) {
                    // Increment the count and check if it equals k
                    st.pop(); // If the count reaches k, pop the character from the stack
                }
            }
            else {
                st.push({c, 1}); // Push a new pair onto the stack with the current character 
                //and a count of 1
            }
        }

        string ans = "";
        while (!st.empty()) {
            // While the stack is not empty
            ans = string(st.top().second, st.top().first) + ans;
            // Append characters to the result string based on their counts
            st.pop(); // Remove the character from the stack
        }

        return ans; // Return the result string with consecutive duplicates removed
    }
};

//Time complexity : O(n)
//Space complexity : O(n)