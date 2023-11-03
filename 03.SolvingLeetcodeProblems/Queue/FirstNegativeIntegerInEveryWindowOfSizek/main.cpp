//GFG PROBLEM
//First negative integer in every window of size k

// 1. Brute force approach (TLE)

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> result; // Create a vector to store the results.
    
    // Iterate through the array, considering each window of size K.
    for (long long i = 0; i <= N - K; i++) {
        long long firstNegative = 0; // Initialize the variable to store the first negative integer in the current window.
        
        // Check each element in the current window to find the first negative integer.
        for (long long j = 0; j < K; j++) {
            if (A[i + j] < 0) {
                firstNegative = A[i + j]; // Update the firstNegative if a negative integer is found.
                break; // Exit the loop as we have found the first negative integer.
            }
        }
        
        result.push_back(firstNegative); // Add the first negative integer to the result vector.
    }
    
    return result; // Return the result vector with first negative integers for each window.
}

//Time Complexity: O(N * K)
//Space Complexity: O(1)

// 2. Optimized Deque approach

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq; // Create a deque to store indices of negative elements.
    vector<long long int> ans; // Create a vector to store the final answers.

    // Processing the first window of size K.
    for (int i = 0; i < K; i++) {
        if (A[i] < 0) {
            dq.push_back(i); // If the element is negative, add its index to the deque.
        }
    }

    // Store the answer for the first K-sized window.
    if (dq.size() > 0) {
        ans.push_back(A[dq.front()]); // Add the first negative element's value to the answer.
    } else {
        ans.push_back(0); // If no negative element is found in the window, add 0 to the answer.
    }

    // Processing for the remaining windows.
    for (int i = K; i < N; i++) {
        if (!dq.empty() && (i - dq.front() >= K)) {
            dq.pop_front(); // Remove indices that are no longer in the current window.
        }
        
        // Adding the next element in the window.
        if (A[i] < 0) {
            dq.push_back(i); // If the element is negative, add its index to the deque.
        }
        
        // Store the answer for the current window.
        if (dq.size() > 0) {
            ans.push_back(A[dq.front()]); // Add the first negative element's value to the answer.
        } else {
            ans.push_back(0); // If no negative element is found in the window, add 0 to the answer.
        }
    }
    
    return ans; // Return the final answer vector with first negative integers for each window.
}

//Time Complexity: O(N) 
//Space Complexity: O(K)

/*--------------------------------------------------*/

// 3. Sliding Window Appraoch

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> result; // Create a vector to store the results.
    long long left = 0, right = 0, count = 0; // Initialize pointers and a count.
    
    // Iterate through the array using a sliding window approach.
    while (right < N) {
        if (A[right] < 0)
            count++; // Increase the count if the element in the current window is negative.
        
        if (right - left + 1 < K) {
            right++; // Expand the window until it reaches size K.
        } else if (right - left + 1 == K) {
            if (count > 0)
                result.push_back(A[left]); // Add the first negative integer to the result.
            else
                result.push_back(0); // No negative integer found in the window, so add 0.
            
            if (A[left] < 0)
                count--; // Reduce the count if the left element is negative.
            
            left++; // Slide the window to the right.
            right++;
        }
    }
    
    return result; // Return the result vector with first negative integers for each window.
}

//Time Complexity: O(N)
//Space Complexity: O(1))
