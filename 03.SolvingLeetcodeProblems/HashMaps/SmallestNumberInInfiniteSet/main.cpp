//2336. Smallest Number in Infinite Set

#include <iostream>
#include <vector>
#include <priority_queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

//Appraoch 1 : Brute Force Approach with Linear Search
class SmallestInfiniteSet {
public:
    // Brute force approach using a vector and linear search
    vector<bool> nums;
    int i; // pointer to current smallest

    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);
        i = 1;
    }

    // Pop and return the smallest element
    int popSmallest() {
        int result = i;

        nums[i] = false;

        for (int j = i + 1; j < 1001; j++) {
            if (nums[j] == true) {
                i = j;
                break;
            }
        }

        return result;
    }

    // Add a number back to the set
    void addBack(int num) {
        nums[num] = true;

        if (num < i) {
            i = num;
        }
    }
};

// Time Complexity: O(n) for popSmallest, O(1) for addBack
// Space Complexity: O(1)

/*******************************************************************************************/

//Appraoch 2 : Improved Approach with Priority Queue
class SmallestInfiniteSet {
public:
    // Improved approach using a priority queue and unordered_set
    int currentSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        currentSmallest = 1;
    }

    // Pop and return the smallest element
    int popSmallest() {
        int result;

        if (!pq.empty()) {
            result = pq.top();
            pq.pop();
            st.erase(result);
        } else {
            result = currentSmallest;
            currentSmallest += 1;
        }

        return result;
    }

    // Add a number back to the set
    void addBack(int num) {
        if (num >= currentSmallest || st.find(num) != st.end())
            return;

        st.insert(num);
        pq.push(num);
    }
};

// Time Complexity: O(log n) for popSmallest, O(log n) for addBack
// Space Complexity: O(n)

/*----------------------------------------------------------------------------------*/

//Appraoch 3 : Optimized Approach with Set
class SmallestInfiniteSet {
public:
    // Optimized approach using a set
    set<int> st;
    int currentSmallest;

    SmallestInfiniteSet() {
        currentSmallest = 1;
    }

    // Pop and return the smallest element
    int popSmallest() {
        int result;

        if (!st.empty()) {
            result = *st.begin();
            st.erase(st.begin());
        } else {
            result = currentSmallest;
            currentSmallest += 1;
        }
        return result;
    }

    // Add a number back to the set
    void addBack(int num) {
        if (num >= currentSmallest || st.find(num) != st.end())
            return;

        st.insert(num);
    }
};

// Time Complexity: O(log n) for popSmallest, O(log n) for addBack
// Space Complexity: O(n)
