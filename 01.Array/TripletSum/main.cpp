//1. Brute force approach
#include <bits/stdc++.h> 
#include <set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    set<vector<int>> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == K) {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);

                    sort(triplet.begin(), triplet.end());
                    if(visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    return ans;
}


//2. Two pointer approach 1. however this does not not handle  duplicate elements in 
//the input array explicitly by skipping over duplicates using the following loop construct:
/*while (i + 1 < n && arr[i] == arr[i + 1]) {
    i++;
}*/
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans; // Initialize result vector

    sort(arr.begin(), arr.end()); // Sort the array in non-decreasing order

    // Iterate through the array using a for loop, stopping at the third-last element
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1; // Initialize left pointer
        int right = n - 1; // Initialize right pointer

        // Use a while loop to move the pointers towards each other
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right]; // Calculate sum of three elements

            if (sum == K) { // If sum equals target K, add triplet to result vector and move pointers
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;
            } else if (sum < K) { // If sum is less than K, move left pointer to right
                left++;
            } else { // If sum is greater than K, move right pointer to left
                right--;
            }
        }
    }

    // Check if result vector is empty
    if (ans.empty()) {
        return {{-1}}; // Return vector containing -1 if no triplets found
    } else {
        return ans; // Return result vector if triplets found
    }
}


/*Brute Force
The most trivial approach would be to find all triplets of the array and count all such triplets whose ‘SUM’ = 'K'.
We can find the answer using three nested loops for three different indexes and check if the values at those indexes sum up to 'K'.
Create a set  to keep the track of triplets we have visited. Run first loop from i = 0 to i = ‘N’ - 3, second loop from j = i + 1 to j = ‘N’ - 2 and third loop from ‘K’ = j + 1 to ‘K’ = ‘N’ - 1.
Check if ‘ARR[i]’ + ‘ARR[j]’ + ‘ARR[K]’ = ‘K’
If the triplet is not present in the set, then print the triplet and insert the triplet into the set since we need distinct triplets only.
Else continue.
Time Complexity
O(N ^ 3), where N is the number of elements in the array.

 

For every possible candidate for finding triplets, we are using three nested for loops Thus, the complexity here grows by the order of O(N ^ 3).

Space Complexity
O(1), as we are using constant extra memory.*/

 /*
        
    Time Complexity: O(N^3)
    Space Complexity: O(1)

    Where N is the number of elements in the array.

 */

#include<set>

vector<vector<int>> findTriplets(vector<int>arr, int n, int K)  {

    // Set to keep the track of visited triplets.
    set<vector<int>>visited;
    vector<vector<int>>ans;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // If we find a valid triplet.
                if (arr[i] + arr[j] + arr[k] == K) {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);
                    // Sorting the triplet track distinct triplets.
                    sort(triplet.begin(), triplet.end());
                    if (visited.find(triplet) == visited.end()) {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }

    return ans;

} 

/*Two pointers
Sort the array in non-decreasing order because after the array is sorted, we don’t have to process the same elements multiple 
times and hence we don’t have to explicitly keep track for distinct triplets. The other advantage of sorting the array is that 
if we have some value and we require a greater value, we know we have to look in only a single direction.
Now since we want triplets such that x + y + z = ‘K’, we have x+ y =  ‘K’ - z and now we can fix z as arr[i]. So we want to 
find the sum of two numbers x and y as ‘K’ - arr[i] in the array.
Let us assume that we are the ith index of the array and initialise variable target to ‘K’ - ‘ARR[i]’.
So now we just need to find two elements x, y such that target = x + y.
We will use two pointers, one will start from i+1, and the other will start from the end of the array.
Let the two pointers be ‘FRONT’ and ‘BACK’, where ‘FRONT’ = i + 1 and ‘BACK’ = n - 1. Let ‘SUM’ = x + y, where x = ‘ARR[FRONT]’ 
and y = ‘ARR[BACK]’. We have to find the triplets such that ‘TARGET’ = ‘SUM’.
While ‘FRONT’ < ‘BACK’, there will be 3 cases:
if ('SUM' < ‘TARGET’), we will have to increase the sum and hence increment front pointer as we have sorted the array and to 
increase the sum, the greater element will always be present after the front index.
Else if ('SUM' > ‘TARGET’), we will have to decrease the sum and hence decrease the ‘BACK’ pointer. The reason for this is 
exactly similar to the above point
Else print the triplet and since we want distinct triplets,  do the following.
Increment the front pointer until ‘ARR[FRONT]’ = x and ‘FRONT’ < ‘BACK’.
Decrement the back pointer until ‘ARR[BACK]’ = y and ‘FRONT’ < ‘BACK’.
While ‘ARR[i]’ = ‘ARR[i+1]’, keep on incrementing i, this will automatically ensure that we are only finding distinct triplets.
Time Complexity
O(N ^ 2),  where N is the number of elements in the array.

 

For every possible candidate for target, we can find if there are valid X and Y in O(N) time. Thus the complexity will be 
O(N ^ 2).

Space Complexity
O(1), as we are using constant extra space.*/

 /*

    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where N is the number of elements in the array.

*/
// Two pointer approach 2.
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>>ans;
    // Sorting the vector.
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int target = K - arr[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back) {
            int sum = arr[front] + arr[back];

            // Finding answer which starts from arr[i].
            if (sum < target) {
                front++;
            }

            else if (sum > target) {
                back--;
            }

            else {
                int x = arr[front];
                int y = arr[back];
                ans.push_back({arr[i], arr[front], arr[back]});

                // Incrementing front pointer until we reach a different number.
                while (front < back && arr[front] == x) {
                    front++;
                }
                // Decrementing last pointer until we reach a different number.
                while (front < back && arr[back] == y) {
                    back--;
                }
            }
        }

        // Ensuring that we don't encounter duplicate values for arr[i].
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return ans;
}

// Two pointer approach 3.
#include <bits/stdc++.h>

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end()); // sort the input array

    for(int i = 0; i < n-2; i++) {
        int left = i + 1;
        int right = n - 1;

        while( left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == K) {
                vector<int> temp = {arr[i], arr[left], arr[right]};
                ans.push_back(temp);
                left++;
                right--;
                
                // Ignore duplicate values for the second element
                while(left < right && arr[left] == arr[left-1]) {
                    left++;
                }
                // Ignore duplicate values for the third element
                while(left < right && arr[right] == arr[right+1]) {
                    right--;
                }
            } else if(sum < K) {
                left++;
            } else {
                right--;
            }

        }
        // Ignore duplicate values for the first element
        while( i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return ans;
}
 