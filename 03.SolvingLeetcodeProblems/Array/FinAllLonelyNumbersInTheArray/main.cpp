//2150. Find All Lonely Numbers in the Array

#include <iostream>
using namespace std;

vector<int> findLonelyNumbers(vector<int>& nums) {
    unordered_map<int, int> frequencyMap; // Stores the frequency of each number
    vector<int> lonelyNums; // Stores the lonely numbers

    // Count the frequency of each number
    for (int num : nums) {
        frequencyMap[num]++; // Increment the frequency count of the number
    }

    // Check if each number is lonely
    for (auto& pair : frequencyMap) {
        int num = pair.first; // Get the number from the pair
        int frequency = pair.second; // Get the frequency from the pair

        // Check if the number is lonely
        if (frequency == 1 && frequencyMap.count(num - 1) == 0 && frequencyMap.count(num + 1) == 0) {
            lonelyNums.push_back(num); // Add the lonely number to the result vector
        }
    }

    return lonelyNums; // Return the vector of lonely numbers
}

