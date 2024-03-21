//767. Reorganize String

#include <bits/stdc++.h>
using namespace std;

//Appraoch 1 : Using priority queue (max heap)

class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        int n = s.length();

        vector<int> count(26, 0);

        // Counting occurrences of each character
        for (char &ch : s) {
            count[ch - 'a']++;

            // Checking if any character's count exceeds half the length of the string
            if (count[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        // Initializing priority queue to sort characters by frequency
        priority_queue<P, vector<P>> pq;

        // Pushing characters and their counts into priority queue
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] > 0) {
                pq.push({count[ch - 'a'], ch});
            }
        }

        string ans = "";

        // Constructing the result string by alternating characters from priority queue
        while (pq.size() >= 2) {
            auto P1 = pq.top();
            pq.pop();

            auto P2 = pq.top();
            pq.pop();

            ans.push_back(P1.second);
            ans.push_back(P2.second);

            // Decrementing counts and pushing back into priority queue if count > 0
            P1.first--;
            P2.first--;

            if (P1.first > 0) {
                pq.push(P1);
            }

            if (P2.first > 0) {
                pq.push(P2);
            }
        }

        // If there is one character left in the priority queue, append it to the result
        if (!pq.empty()) {
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};

/*Time Complexity: O(n log k), where n is the length of the input string and k is the size 
of the alphabet (26 in this case). The priority queue operations dominate the time complexity.

Space Complexity: O(k), where k is the size of the alphabet. The space required is for the count 
array and the priority queue.*/

/*-----------------------------------------------------*/

//Approach 2: Counting and Direct Placement

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        vector<int> count(26, 0);

        int maxFreq = 0;
        char charMaxFreq;

        // Counting occurrences of each character and finding the character with max frequency
        for (char &ch : s) {
            count[ch - 'a']++;

            if (count[ch - 'a'] > maxFreq) {
                maxFreq = count[ch - 'a'];
                charMaxFreq = ch;
            }

            // Checking if any character's count exceeds half the length of the string
            if (count[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        string ans = s;
        int i = 0;

        // Placing the character with max frequency at alternate positions
        while (count[charMaxFreq - 'a'] > 0) {
            ans[i] = charMaxFreq;
            i += 2;
            count[charMaxFreq - 'a']--;
        }

        // Placing the rest of the characters in empty slots in alternate fashion
        for (char ch = 'a'; ch <= 'z'; ch++) {
            while (count[ch - 'a'] > 0) {
                if (i >= n)
                    i = 1;

                ans[i] = ch;
                i += 2;
                count[ch - 'a']--;
            }
        }

        return ans;
    }
};

/*Time Complexity: O(n), where n is the length of the input string. The time complexity is dominated 
by the single pass through the input string.

Space Complexity: O(k), where k is the size of the alphabet. The space required is for the count array.*/
