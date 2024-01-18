//299. Bulls and Cows

#include <iostream>
#include <map>
#include <string>
using namespace std;

// This is a C++ implementation of a function to calculate the "bulls and cows" hint for a given secret and guess string.


class Solution {
public:
    // Function to calculate the bulls and cows hint.
    string getHint(string secret, string guess) {

        // Maps to store the frequency of characters in the secret and guess strings.
        map<char, int> secretMap, guessMap;
        
        // Variables to count the number of bulls and cows.
        int bulls = 0, cows = 0;

        // Loop through each character in the strings.
        for (int i = 0; i < secret.length(); i++) {

            // Check if the characters at the same position are the same (bulls).
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                // If not the same, update the frequency maps for both secret and guess strings.
                secretMap[secret[i]]++;
                guessMap[guess[i]]++;
            }
        }

        // Iterate through the frequency map of the secret string.
        for (auto j : secretMap) {
            // If the character exists in the frequency map of the guess string.
            if (guessMap.find(j.first) != guessMap.end()) {
                // Count the number of cows by taking the minimum of frequencies.
                cows += min(j.second, guessMap[j.first]);
            }
        }

        /*ORfor (const auto& secretDigit : secretMap) {
    char digit = secretDigit.first;
    int secretFrequency = secretDigit.second;

    if (guessMap.find(digit) != guessMap.end()) {
        int guessFrequency = guessMap[digit];
        cows += min(secretFrequency, guessFrequency);
    }
}
*/

        // Return the bulls and cows hint as a string.
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

/*Time Complexity:

The time complexity of this code is O(n), where n is the length of the input strings secret and guess. 
This is because the code iterates through each character in the strings once.

Space Complexity:

The space complexity is O(1) in terms of the input size, as the maximum number of distinct characters 
is limited (26 uppercase letters). The use of maps doesn't depend on the size of the input strings.*/