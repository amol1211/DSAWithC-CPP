//219. Contains Duplicate II

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        // Create an unordered_map to store the elements of the array and their last seen indices.
        unordered_map<int, size_t> map;

        // Loop through the array using 'i' as the index.
        for (size_t i = 0; i < nums.size(); ++i)
        {
            // Check if the current element (nums[i]) is already in the unordered_map.
            if (map.count(nums[i]))
            {
                // If it's present, check if the absolute difference between the current index (i)
                // and the last seen index of this element (map[nums[i]]) is less than or equal to 'k'.
                // If it is, that means we have found two distinct indices with the same element
                // that satisfy the condition abs(i - map[nums[i]]) <= k, so we return true.
                if (i - map[nums[i]] <= k)
                    return true;
            }

            // If the current element is not already in the unordered_map or the condition above
            // is not met, update its last seen index in the unordered_map to the current index (i).
            map[nums[i]] = i;
        }

        // If we reach this point, it means no two distinct indices with the same element
        // satisfying the condition were found in the entire array, so we return false.
        return false;
    }
};
