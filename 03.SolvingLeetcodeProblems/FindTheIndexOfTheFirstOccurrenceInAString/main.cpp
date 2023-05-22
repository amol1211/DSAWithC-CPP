//28. Find the Index of the First Occurrence in a String

//Approach 1: Brute Force

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        
        if (needleLen == 0)
            return 0;  // Edge case: empty needle, it is considered to be found at index 0.
        
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            int j;
            for (j = 0; j < needleLen; j++) {
                if (haystack[i + j] != needle[j])
                    break;  // Mismatch found, break inner loop.
            }
            if (j == needleLen)
                return i;  // Found needle at index i.
        }
        
        return -1;  // Needle not found in haystack.
    }
};

//Time complexity: O((N - M + 1) * M)
//Space complexity: O(1)

/*------------------------------------------------------------------------------*/

//Approach 2: Knuth-Morris-Pratt (KMP) Algorithm

//The KMP algorithm provides a more efficient solution by utilizing the pattern 
//of needle itself. It precomputes a prefix array that helps avoid unnecessary comparisons. 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        
        if (needleLen == 0)
            return 0;  // Edge case: empty needle, it is considered to be found at index 0.
        
        vector<int> lps = computeLPS(needle);
        
        int i = 0;  // Pointer for haystack
        int j = 0;  // Pointer for needle
        
        while (i < haystackLen) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                
                if (j == needleLen)
                    return i - j;  // Found needle at index (i - j)
            } else {
                if (j > 0)
                    j = lps[j - 1];  // Move j to the previous longest proper prefix
                else
                    i++;  // No proper prefix found, move i to the next position
            }
        }
        
        return -1;  // Needle not found in haystack.
    }
    
private:
    vector<int> computeLPS(const string& needle) {
        int len = needle.length();
        vector<int> lps(len, 0);  // Longest proper prefix which is also suffix
        
        int i = 1;  // Pointer for lps
        int j = 0;  // Pointer for needle
        
        while (i < len) {
            if (needle[i] == needle[j]) {
                j++;
                lps[i] = j;
                i++;
            } else {
                if (j > 0)
                    j = lps[j - 1];  // Move j to the previous longest proper prefix
                else {
                    lps[i] = 0;  // No proper prefix found, set lps[i] = 0
                    i++;
                }
            }
        }
        
        return lps;
    }
};

//The time complexity of the second approach, which uses the Knuth-Morris-Pratt 
//(KMP) algorithm, is O(N + M), where N is the length of the haystack and M is 
//the length of the needle.
////Space complexity: O(M)