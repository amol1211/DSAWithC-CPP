#include <iostream>
using namespace std;

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