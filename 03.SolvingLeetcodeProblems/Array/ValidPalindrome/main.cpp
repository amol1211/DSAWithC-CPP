// 125. Valid Palindrome
#include <iostream>
using namespace std;

// 1. Two-pointer approach

class Solution {
public:
    bool isPalindrome(string s) {
        string curr = ""; // Initialize a new string to store only alphanumeric characters
        for(int i = 0; i < s.size(); i++)
            // Check if the character is alphanumeric
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                curr += s[i]; // If it is, append it to the curr string
        
        // Convert curr string to lowercase
        transform(curr.begin(),curr.end(), curr.begin(), :: tolower);
        
        int i = 0, j = curr.size() - 1; // Initialize pointers i and j
        while(i <= j)
        {
            if(curr[i] != curr[j]) // Check if the characters at i and j are the same
                return false; // If they're not, return false
            i++; j--; // Increment i and decrement j
        }
        return true; // If we reach here, the string is a palindrome, so return true   
    }
};

/*-----------------------------------------------------------------------------------------*/

// 2. Reverse string approach

class Solution {
public:
    bool isPalindrome(string s) {
        string curr1 = ""; // Initialize a new string to store only alphanumeric characters
        for(int i = 0; i < s.size(); i++)
            // Check if the character is alphanumeric
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                curr1 += s[i]; // If it is, append it to the curr string
        
        // Convert curr1 string to lowercase
		transform(curr1.begin(),curr1.end(), curr1.begin(), :: tolower);
        
        string curr2 = curr1; // Create a new string that is a copy of curr1
        reverse(curr2.begin(), curr2.end()); // Reverse the copy of curr1
        
        if(curr1 == curr2) // Check if the original and reversed string are the same
            return true; // If they are, return true
        
        return false; // If they're not, return false
    }
};

/*------------------------------------------------------------------------------------------*/

// 3. Alphanumeric check approach

class Solution {
public:
    bool isPalindrome(string s) {
        string curr = ""; // Initialize a new string to store only alphanumeric characters
        for(int i = 0; i < s.size(); i++)
            if(isalnum(s[i])) // Check if the character is alphanumeric
                curr.push_back(s[i]); // If it is, append it to the curr string
        
        // Convert curr string to lowercase
        transform(curr.begin(),curr.end(),curr.begin(), :: tolower);
        
        int i = 0, j = curr.size() - 1; // Initialize pointers i and j
        while(i <= j)
        {
            if(curr[i] != curr[j]) // Check if the characters at i and j are the same
                return false; // If they're not, return false
            i++; j--; // Increment i and decrement j
        }
        return true; // If we reach here, the string is a palindrome, so return true 
    }
};

/*---------------------------------------*/
 
 // 4. Recursive approach

#include <string>
#include <cctype>

class Solution {
private:
    bool isPalindromeHelper(const std::string &s, int i, int j) {
        // Base case: an empty string or a single character is a palindrome
        if (s.empty() || i >= j) {
            return true;
        }

        // Skip non-alphanumeric characters
        while (i < j && !std::isalnum(s[i])) {
            i++;
        }

        while (i < j && !std::isalnum(s[j])) {
            j--;
        }

        // Convert characters to lowercase for case-insensitive comparison
        char charI = std::tolower(s[i]);
        char charJ = std::tolower(s[j]);

        // Compare characters
        if (charI != charJ) {
            return false;
        } else {
            // Recursive call with updated indices
            return isPalindromeHelper(s, i + 1, j - 1);
        }
    }

public:
    bool isPalindrome(std::string s) {
        return isPalindromeHelper(s, 0, s.size() - 1);
    }
};

//Time complexity : O(n)
////Space complexity : O(n)