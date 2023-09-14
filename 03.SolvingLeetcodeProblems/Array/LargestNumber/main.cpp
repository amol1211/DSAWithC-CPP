class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;  // Store string representations of integers
        for(auto i:num)
            arr.push_back(to_string(i));  // Convert each integer to string and add to arr vector
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });  
        // Sort arr based on custom comparison function
        string res;  // Result string
        for(auto s:arr)
            res+=s;  // Concatenate all strings in arr to form the result
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);  // Remove leading zeros from the result
        return res;  // Return the final result
    }
};
