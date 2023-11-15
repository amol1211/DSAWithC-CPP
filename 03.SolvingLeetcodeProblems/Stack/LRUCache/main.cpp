//146. LRU Cache

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1.Brute force

// The LRUCache class is defined to implement a Least Recently Used (LRU) cache.
class LRUCache {
public:
    // 'cache' is a vector of pairs representing key-value pairs stored in the cache.
    vector<pair<int, int>> cache;

    // 'n' represents the capacity of the cache.
    int n;

    // Constructor to initialize the LRUCache with a specified capacity.
    LRUCache(int capacity) {
        n = capacity;
    }
    
    // Method to retrieve the value associated with a given key from the cache.
    int get(int key) {
        // Iterate through the cache to find the key.
        for (int i = 0; i < cache.size(); i++) {
            // If the key is found, update its position to make it the most recently used.
            if(cache[i].first == key) {
                int val = cache[i].second;

                // Store the key-value pair in a temporary variable.
                pair<int, int> temp = cache[i];

                // Erase the key-value pair from its current position.
                cache.erase(cache.begin() + i);

                // Push the key-value pair to the back of the cache to mark it as the most recently used.
                cache.push_back(temp);

                // Return the value associated with the key.
                return val;
            }
        }

        // If the key is not found, return -1.
        return -1;
    }
    
    // Method to insert a new key-value pair into the cache or update the value if the key already exists.
    void put(int key, int value) {
        // Iterate through the cache to find the key.
        for (int i = 0; i < cache.size(); i++) {
            // If the key is found, update its value and move it to the most recently used position.
            if(cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        // If the cache is at full capacity, remove the least recently used key-value pair from the front.
        if (cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            // If the cache is not at full capacity, simply add the new key-value pair to the back.
            cache.push_back({key, value});
        }
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*------------------------------------------------------------*/

//2. Using DLL and map approach

// The LRUCache class is defined to implement a Least Recently Used (LRU) cache.
class LRUCache {
public:
    // 'dll' is a doubly linked list representing the keys in the order of their recent usage.
    list<int> dll; // key
    
    // 'mp' is a map that stores key-value pairs, along with an iterator to the corresponding node in 'dll'.
    map<int, pair<list<int>::iterator, int>> mp;

    // 'n' represents the capacity of the cache.
    int n;

    // Constructor to initialize the LRUCache with a specified capacity.
    LRUCache(int capacity) {
        n = capacity;
    }

    // Helper method to update the order of recently used keys in 'dll'.
    void makeRecentlyUsed(int key) {
        // Remove the key from its current position in 'dll'.
        dll.erase(mp[key].first);

        // Push the key to the front of 'dll' to mark it as the most recently used.
        dll.push_front(key);

        // Update the iterator in 'mp' to point to the new position of the key in 'dll'.
        mp[key].first = dll.begin();
    }

    // Method to retrieve the value associated with a given key from the cache.
    int get(int key) {
        // If the key is not found in 'mp', return -1.
        if (mp.find(key) == mp.end())
            return -1;

        // Update the order of recently used keys in 'dll'.
        makeRecentlyUsed(key);

        // Return the value associated with the key.
        return mp[key].second;    
    }
    
    // Method to insert a new key-value pair into the cache or update the value if the key already exists.
    void put(int key, int value) {
        // If the key already exists in 'mp', update its value and mark it as the most recently used.
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else {
            // If the key is not in 'mp', add it to the front of 'dll' and update 'mp'.
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        // If the cache is at full capacity, remove the least recently used key-value pair.
        if (n < 0) {
            // Get the key to be deleted from the back of 'dll'.
            int key_tobe_del = dll.back();

            // Erase the key-value pair from 'mp'.
            mp.erase(key_tobe_del);

            // Remove the least recently used key from the back of 'dll'.
            dll.pop_back();

            // Increment the available capacity.
            n++;
        }
    }
};

//Time complexity : O(1)
//Space complexity : O(n)