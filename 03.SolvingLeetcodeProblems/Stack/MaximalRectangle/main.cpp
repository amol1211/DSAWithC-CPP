//85. Maximal Rectangle

class Solution {
private:
    // Define a private function to calculate the largest rectangle area in a histogram.
    int largestRectangleArea(vector<int> &height) {
        stack<int> s; // Create a stack to maintain indices.
        height.push_back(0); // Add a sentinel element to the end of the height vector.
        int maxSize = 0; // Initialize a variable to keep track of the maximum rectangle area.
        for(int i = 0; i < height.size(); i++){
            if(s.empty() || height[i] >= height[s.top()]){
                // If the stack is empty or the current height is greater than the height 
                //at the top of the stack, push the current index onto the stack.
                s.push(i);
            }
            else{
                int temp = height[s.top()]; // Get the height at the top of the stack.
                s.pop(); // Pop the index from the stack.
                int width;
                if (s.empty()) {
                    width = i; // If the stack is empty, the width is from the beginning of the histogram 
                    //to the current index.
                } else {
                    width = i - 1 - s.top(); 
                    // Otherwise, the width is from the index at the top of the stack to the current index.
                }
                maxSize = max(maxSize, temp * width); // Calculate and update the maximum rectangle area 
                //for the current histogram.
                i--; // Decrement i to consider the same index again, as there could be multiple 
                //rectangles with the same height.
            }
        }
        return maxSize; // Return the maximum rectangle area.
    }

public:
    // Define the public function to calculate the maximal rectangle area in a binary matrix.
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()){
            return 0; // If the input matrix is empty, return 0.
        }
        int maxRec = 0; // Initialize a variable to store the maximum rectangle area.
        vector<int> height(matrix[0].size(), 0); // Create a vector to store the heights of the rectangles.
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0; // If the current cell contains '0', set the height at this position to 0.
                }
                else{
                    height[j]++; // If the current cell contains '1', increment the height at this position.
                }
            }
            maxRec = max(maxRec, largestRectangleArea(height)); // Calculate the maximum rectangle area 
            //for the current row and update "maxRec" if needed.
        }
        return maxRec; // Return the maximum rectangle area.
    }
};

//Time complexity is O(n * m)
//Space complexity is O(m)
