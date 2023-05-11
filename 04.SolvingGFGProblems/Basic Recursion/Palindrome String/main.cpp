
//Approach 1: Using reverse string comparison

int isPalindrome(string S) {
    string revS = S;  // make a copy of the original string
    reverse(revS.begin(), revS.end());  // reverse the copy

    // compare the original string with the reversed string
    if (S == revS) {
        return 1;  // palindrome
    } else {
        return 0;  // not a palindrome
    }
}

//Approach 2: Using two-pointers

int isPalindrome(string S) {
    int start = 0, end = S.length() - 1;  // initialize two pointers

    // compare the characters at the two pointers
    while (start < end) {
        if (S[start] != S[end]) {
            return 0;  // not a palindrome
        }
        start++;
        end--;
    }

    return 1;  // palindrome
}

//Approach 3: Using stack

int isPalindrome(string S) {
    stack<char> st;  // create a stack

    // push all the characters onto the stack
    for (char c : S) {
        st.push(c);
    }

    // pop each character from the stack and append it to a new string
    string revS = "";
    while (!st.empty()) {
        revS += st.top();
        st.pop();
    }

    // compare the original string with the reversed string
    if (S == revS) {
        return 1;  // palindrome
    } else {
        return 0;  // not a palindrome
    }
}

//all these approaches have the same time complexity of O(N), where N is the 
//length of the input string, and the space complexity of O(N) in the worst case. 
//The first approach may have a higher space complexity than the other two approaches 
//due to the need to make a copy of the input string.