//460. LFU Cache

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// LFUCache class definition
class LFUCache {
private:
    // Member variables
    int cap; // Capacity of the cache
    int size; // Current size of the cache
    unordered_map<int, list<vector<int>>::iterator> mp; // Map to store key -> iterator of list of 
    //vectors {key, value, frequency}
    map<int, list<vector<int>>> freq; // Map to store frequency -> list of vectors {key, value, frequency}

public:
    // Constructor to initialize the LFUCache with a given capacity
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    // Function to update the frequency of a key and move it to the front of its frequency list
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]); // Reference to the vector corresponding to the key

        int value = vec[1]; // Extract the value from the vector
        int f = vec[2]; // Extract the frequency from the vector

        // Remove the key from its current frequency list
        freq[f].erase(mp[key]);

        // If the frequency list becomes empty, remove the frequency from the map
        if (freq[f].empty())
            freq.erase(f);

        f++; // Increment the frequency

        // Add the key to the front of the new frequency list
        freq[f].push_front(vector<int>({key, value, f}));

        // Update the iterator in the map to point to the new position of the key in the frequency list
        mp[key] = freq[f].begin();    
    }
    
    // Function to get the value of a key and update its frequency
    int get(int key) {
        // If the key is not present in the cache, return -1
        if (mp.find(key) == mp.end())
             return -1;

        // Reference to the vector corresponding to the key
        auto &vec = (*(mp[key]));

        int value = vec[1]; // Extract the value from the vector

        // Update the frequency of the key and move it to the front of its frequency list
        makeMostFrequentlyUsed(key);

        return value; // Return the value associated with the key     
    }
    
    // Function to insert a key-value pair into the cache
    void put(int key, int value) {
        // If the capacity is 0, do nothing
        if (cap == 0) 
             return;

        // If the key is already present in the cache
        if (mp.find(key) != mp.end())  {
            auto &vec = (*(mp[key]));
            vec[1] = value; // Update the value associated with the key
            // Update the frequency of the key and move it to the front of its frequency list
            makeMostFrequentlyUsed(key);
        }     
        // If the key is not present and there is space in the cache
        else if (size < cap) {
            size++; // Increment the size
            // Add the key to the front of the frequency list with frequency 1
            freq[1].push_front(vector<int>({key, value, 1}));
            // Update the iterator in the map to point to the new position of the key in the frequency list
            mp[key] = freq[1].begin();
        }
        // If the cache is full and a key needs to be evicted
        else {
            // Get the least frequently used frequency list
            auto &which_list = freq.begin()->second;

            // Get the key to be deleted (the least frequently used key)
            int key_delete = (which_list.back())[0];

            // Remove the key from the least frequently used frequency list
            which_list.pop_back();

            // If the frequency list becomes empty, remove the frequency from the map
            if(which_list.empty())
                 freq.erase(freq.begin()->first);

            // Add the new key to the front of the frequency list with frequency 1
            freq[1].push_front(vector<int>({key, value, 1}));

            // Remove the evicted key from the map
            mp.erase(key_delete);
            // Update the iterator in the map to point to the new position of the key in the frequency list
            mp[key] = freq[1].begin();
        }
    }
};

// Time Complexity:
// - The 'get' and 'put' operations involve accessing and updating elements in maps and lists, 
//which are generally O(1).
// - The 'makeMostFrequentlyUsed' function also involves O(1) operations on maps and lists.
// - Overall, the time complexity of each operation is O(1).

// Space Complexity:
// - The space complexity is O(capacity), where 'capacity' is the capacity of the LFUCache.
// - The space is used to store key-value pairs in maps and lists, and the maximum space required is 'capacity'.

// Time Complexity: O(1)
//Space complexity: O(capacity)