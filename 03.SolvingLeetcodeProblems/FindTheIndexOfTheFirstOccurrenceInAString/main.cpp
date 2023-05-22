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

/*------------------------------------------------------------------------------*/