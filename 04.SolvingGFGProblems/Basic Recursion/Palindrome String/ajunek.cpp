#include <iostream>
using namespace std;

class Solution {
    public:
    int isPalindrome(string S) {
        string revS = S;
        reverse(revS.begin(), revS.end());

        if (S == revS) {
            return 1;
        } else {
            return 0;
        }

    }
};

/*---------------------------------------------------*/

int isPalindrome(string S) {
    int start = 0; end = S.length() - 1;

    while (start < end) {
        if (S[start] != S[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

/*--------------------------------------------------*/

int isPlaindrome(string S) {
    stach<char> st;
    for (char c: S) {
        st.push(c);
    }

    string revS = "";
    while (!st.empty()) {
        revS += st.top();
        st.pop();
    }

    if (S == revS) {
        return 1;
    } else {
        return 0;
    }
}
