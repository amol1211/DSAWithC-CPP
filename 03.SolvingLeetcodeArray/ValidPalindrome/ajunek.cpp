#include <iostream>
using namespace std;

// 1.Two-pointer approach

class Solution {
	public:
	bool isPalindrome(string s) {
		string st = "";
		for (int i = 0; i < s.size(); i++) 
			if ((s[i] >= 'a' && s[i] <= 'z' ) || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
			st += s[i];
		
		transform(st.begin(), st.end(), st.begin(), :: tolower);

		int i = 0; j = st.size() - 1;
		while (i <= j) {
			if (st[i] != st[j])
			return false;
			i++;
			j--;
		}
		return true;
	}
};

/*-----------------------------------------------------------*/

// 2. Reverse string approach

class Solution {
public:
    bool isPalindrome(string s) {
        string st1 = "";

        for (int i = 0; i < s.size(); i++) 
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                st1 += s[i];

        transform(st1.begin(), st1.end(), st1.begin(), ::tolower);

        string st2 = st1;
        reverse(st2.begin(), st2.end());

        if(st1 == st2)
            return true;

        return false;    
    }
};

/*-------------------------------------------------------------------------------*/

// Alphanumeric check approach

class Solution {
	bool isPalindrome(string s) {
		string st = "";
		for(int i = 0; i < s.size(); i++)
		    if(isalnum(s[i]))
			    st.push_back(s[i]);

		transform(st.begin(), st.end(), st.begin(), :: tolower);

		int i = 0, j = st.size() - 1;
		while (i <= j) {
			if (st[i] != st[j])
			    return false;
				i++; j--;
		}
		return true;		
	}
};

