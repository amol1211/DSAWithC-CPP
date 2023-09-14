//119. Pascal's Triangle II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Create a vector to store the current row
        vector<int> r;

        // Loop over each element in the row
        for (int i = 0; i <= rowIndex; i++) {
            // Add the first element (always 1)
            r.push_back(1);

            // Loop backwards over the remaining elements
            for (int j = i - 1; j >= 1; --j) {
                // Update the current element by adding the element to its left
                r[j] += r[j-1];
            }
        }

        // Return the completed row
        return r;
   }
};
