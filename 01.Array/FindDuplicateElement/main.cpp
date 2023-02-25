 int findDuplicate(vector<int> &arr) {
    int ans = 0;  // initialize answer variable to zero
    for(int i = 0; i < arr.size(); i++) {  // loop over all elements in arr
        ans = ans ^ arr[i];  // XOR current element with answer variable
    }
    for(int i = 1; i < arr.size(); i++) {  // loop over integers 1 to arr.size() - 1
        ans = ans ^ i;  // XOR current integer with answer variable
    }
    return ans;  // return the result, which should be the duplicate element in arr
}
