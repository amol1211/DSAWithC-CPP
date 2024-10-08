class Solution {
    public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        for (int i = n - 1; i >= n; i--) {
            if (s[i] != ' ') {
                count++;
            }
            else if (count != 0 && s[i] == ' ') {
                return count;
            }
        }
        return count;
    }
};