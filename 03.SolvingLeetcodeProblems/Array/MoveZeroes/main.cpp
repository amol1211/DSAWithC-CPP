//283. Move Zeroes
//1. Brute Force Approach:

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};

/*------------------------------------------------------------*/
//2. Two pointer approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nextNonZero = 0; // Position to place the next non-zero element
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[nextNonZero], nums[i]);
                nextNonZero++;
            }
        }
    }
};

/*---------------------------------------------------------------------------*/
//3. Optimized two pointer approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nextNonZero = 0; // Position to place the next non-zero element
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nextNonZero] = nums[i];
                nextNonZero++;
            }
        }
        
        // Fill the remaining positions with zeroes
        for (int i = nextNonZero; i < n; i++) {
            nums[i] = 0;
        }
    }
};

/*-------------------------------------------------------------------------------*/

//4. Using stable_partition with Forward Iterators(using lambda function)

void moveZeroes(vector<int>& nums) {
    // Rearranges elements in 'nums' so that non-zero elements come before zero elements,
    // while maintaining the relative order of non-zero elements.
    stable_partition(begin(nums), end(nums), [](int i) { return i; });
}

/*-----------------------------------------------------------------------------*/

//5. Using stable_partition with Reverse Iterators(Using STL function) 

void moveZeroes(vector<int>& nums) {
    // Rearranges elements in 'nums' in reverse order so that logical NOT of zero elements
    // (i.e., non-zero elements) come before zero elements, maintaining relative order.
    stable_partition(rbegin(nums), rend(nums), logical_not<int>());
}




