// 125. Valid Palindrome
#include <iostream>
using namespace std;

//Two-pointer approach

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

//Reverse string approach

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

//Alphanumeric check approach

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
