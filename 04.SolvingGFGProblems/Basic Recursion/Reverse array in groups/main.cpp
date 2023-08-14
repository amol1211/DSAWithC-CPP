//Approach 1: Using Reverse function

//Time Complexity: O(N)
//Space Complexity: O(1)
void reverseInGroups(vector<long long>& arr, int N, int K){
    for (int i = 0; i < N; i += K) { // loop through the array in increments of K
        int left = i; // left index of the subarray
        int right = min(i + K - 1, N - 1); // to handle case when k is not multiple of n
        while (left < right) { // reverse the subarray
            swap(arr[left++], arr[right--]); // swap the left and right elements and move towards the middle
        }
    }
}


/*----------------------------------------------------------------------------*/

//Approach 2: Using a temporary array

//Time Complexity: O(N)
//Space Complexity: O(K)

void reverseInGroups(vector<long long>& arr, int N, int K) {
    for (int i = 0; i < N; i += K) { // loop through array in groups of size K
        int left = i;
        int right = min(i + K - 1, N - 1); // find the rightmost index of the current group
        vector<long long> temp(K); // create a temporary vector to store the current group
        for (int j = left; j <= right; j++) {
            temp[j - left] = arr[j]; // copy elements from the current group to temp vector
        }
        reverse(temp.begin(), temp.end()); // reverse the temp vector
        for (int j = left; j <= right; j++) {
            arr[j] = temp[j - left]; // copy elements from the reversed temp vector back to the original array
        }
    }
}


/*----------------------------------------------------------------------------*/

//Approach 3: Using a stack

//lTime Complexity: O(N)
//Space Complexity: O(K)

void reverseInGroups(vector<long long>& arr, int N, int K){
stack<long long> s; // create a stack to hold the elements of subarrays
for (int i = 0; i < N; i += K) { // loop through the array with step size of K
int left = i; // set the left index of subarray
int right = min(i + K - 1, N - 1); // set the right index of subarray, taking into account the case when the last subarray is smaller than K
for (int j = left; j <= right; j++) {
s.push(arr[j]); // push the elements of the subarray into the stack
}
for (int j = left; j <= right; j++) {
arr[j] = s.top(); // overwrite the elements of the subarray with the elements popped from the stack
s.pop(); // pop the element from the stack
}
}
}

