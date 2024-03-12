//451. Sort Characters By Frequency

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using priority_queue and unordered_map
// Time Complexity: O(n log k), where n is the length of the input string and k is the number of unique characters in the string.
// Space Complexity: O(n), where n is the length of the input string.

class Solution {
public:
    typedef pair<char, int> P;

    // Custom comparator for priority_queue to sort by frequency
    struct lambda {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second; // heap = max frequency's entry will be on top
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, lambda> pq; // priority queue to store characters and their frequencies

        unordered_map<char, int> mp; // map to store character frequencies

        // Frequency updated in map
        for (char &ch : s) {
            mp[ch]++;
        }

        // Fill in heap from map
        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }

        string result = "";

        // Construct result string by popping from priority_queue
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            result += string(temp.second, temp.first); // append character frequency times
        }

        return result;
    }
};

/*---------------------------------------------------------------------------------------------------------*/

// Approach 2: Using vector and sort
// Time Complexity: O(n log n), where n is the length of the input string.
// Space Complexity: O(1) - Ignoring the output space which is O(n).

class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {
        vector<P> vec(123); // vector to store characters and their frequencies, assuming ASCII characters

        // Updating frequency
        for (char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq + 1};
        }

        // Custom lambda comparator for sorting
        auto lambda = [&](P &p1, P &p2) {
            return p1.second > p2.second; // sort in descending order of frequency
        };

        sort(begin(vec), end(vec), lambda); // sort characters based on frequency

        string result = "";

        // Construct result string from sorted vector
        for (int i = 0; i <= 122; i++) {
            if (vec[i].second > 0) {
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq, ch); // create a string with character repeated according to its frequency

                result += temp; // append to result
            }
        }

        return result;
    }
};

/*For Approach 1:

Time Complexity: Constructing the unordered_map takes O(n), where n is the length of the input string. Constructing the priority_queue takes O(k log k), where k is the number of unique characters in the string. In the worst case, k can be considered as a constant, so overall time complexity would be O(n log k).
Space Complexity: O(n) for the unordered_map and O(k) for the priority_queue, where k is the number of unique characters in the string. Ignoring the output space, the overall space complexity is O(n).

For Approach 2:

Time Complexity: Constructing the vector takes O(1) since the vector size is constant (123). Updating the frequencies takes O(n), where n is the length of the input string. Sorting the vector takes O(k log k), where k is the number of unique characters with non-zero frequencies. In the worst case, k can be considered as a constant, so overall time complexity would be O(n log k).
Space Complexity: O(1) for the vector (ignoring the constant size), and O(n) for other variables (such as result string). Ignoring the output space, the overall space complexity is O(n).*/