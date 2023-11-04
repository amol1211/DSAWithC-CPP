//GFG problem
//

class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q) {
        int n = q.size(); // Get the size of the input queue.
        int half = n / 2; // Calculate the half size.

        // Create two queues to hold the first and second halves.
        queue<int> firstHalf, secondHalf;

        // Separate the input queue into two halves.
        for (int i = 0; i < half; i++) {
            firstHalf.push(q.front()); // Push the front element of the input queue to the firstHalf.
            q.pop(); // Remove the front element from the input queue.
        }

        for (int i = half; i < n; i++) {
            secondHalf.push(q.front()); // Push the front element of the input queue to the secondHalf.
            q.pop(); // Remove the front element from the input queue.
        }

        // Interleave the elements from the two halves and push them back into the input queue.
        while (!firstHalf.empty() || !secondHalf.empty()) {
            if (!firstHalf.empty()) {
                q.push(firstHalf.front()); // Push the front element of firstHalf to the input queue.
                firstHalf.pop(); // Remove the front element from firstHalf.
            }
            if (!secondHalf.empty()) {
                q.push(secondHalf.front()); // Push the front element of secondHalf to the input queue.
                secondHalf.pop(); // Remove the front element from secondHalf.
            }
        }

        vector<int> result;

        // Transfer the rearranged elements from the input queue to a vector for the final result.
        while (!q.empty()) {
            result.push_back(q.front()); // Push the front element of the input queue to the result vector.
            q.pop(); // Remove the front element from the input queue.
        }

        return result; // Return the vector containing the rearranged elements.
    }
};

/*-------------------OR--------------------------------------*/

class Solution {
public:
    vector<int> rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;

        queue<int> firstHalf, secondHalf;

        // Separate the input queue into two halves.
        for (int i = 0; i < half; i++) {
            int element = q.front(); // Get the front element of the input queue.
            firstHalf.push(element); // Push it into the firstHalf.
            q.pop(); // Remove the front element from the input queue.
        }

        for (int i = half; i < n; i++) {
            int element = q.front(); // Get the front element of the input queue.
            secondHalf.push(element); // Push it into the secondHalf.
            q.pop(); // Remove the front element from the input queue.
        }

        // Interleave the elements from the two halves and push them back into the input queue.
        while (!firstHalf.empty() || !secondHalf.empty()) {
            if (!firstHalf.empty()) {
                int element = firstHalf.front(); // Get the front element of the firstHalf.
                q.push(element); // Push it into the input queue.
                firstHalf.pop(); // Remove the front element from firstHalf.
            }
            if (!secondHalf.empty()) {
                int element = secondHalf.front(); // Get the front element of the secondHalf.
                q.push(element); // Push it into the input queue.
                secondHalf.pop(); // Remove the front element from secondHalf.
            }
        }

        vector<int> result;

        // Transfer the rearranged elements from the input queue to a vector for the final result.
        while (!q.empty()) {
            int element = q.front(); // Get the front element of the input queue.
            result.push_back(element); // Push it into the result vector.
            q.pop(); // Remove the front element from the input queue.
        }

        return result; // Return the vector containing the rearranged elements.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

