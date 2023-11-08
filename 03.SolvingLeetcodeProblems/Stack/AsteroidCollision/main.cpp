//735. Asteroid Collision

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// 1. Simple stack approach

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size(); // Get the size of the input vector.
        stack<int> s; // Create a stack to simulate the asteroid collisions.
        
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0 || s.empty()) {
                // If the current asteroid is positive or the stack is empty, push it onto the stack.
                s.push(asteroids[i]);
            }
            else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
                    // While there are positive asteroids on the stack and the current negative asteroid
                    // has a larger absolute value than the positive asteroid on top of the stack, 
                    //pop the positive asteroid.
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(asteroids[i])) {
                    // If the current negative asteroid cancels out the positive asteroid on top of the 
                    //stack, pop the positive asteroid.
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        // If the stack is empty or the top asteroid on the stack is negative, 
                        //push the current negative asteroid onto the stack.
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        
        vector<int> res(s.size()); // Create a vector to store the remaining asteroids.
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            // Transfer the remaining asteroids from the stack to the result vector in reverse order.
            res[i] = s.top();
            s.pop();
        }
        return res; // Return the result vector containing the remaining asteroids.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*-----------------------------------------------------------------------*/

//  2. Optimized stack approach

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;  // Create a stack to simulate the asteroid collisions.
        
        for (int i = 0; i < asteroids.size(); i++) {
            // Iterate through the given asteroid array.
            
            while (!s.empty() && asteroids[i] < 0 && s.top() > 0) {
                // Check if there is a collision between the current negative asteroid (asteroids[i])
                // and the positive asteroid on top of the stack (s.top()).
                
                int sum = asteroids[i] + s.top();  // Calculate the sum of their sizes.

                if (sum < 0) {
                    s.pop();  // If the sum is negative, the positive asteroid is destroyed.
                }
                else if (sum > 0) {
                    asteroids[i] = 0;  // If the sum is positive, the negative asteroid is destroyed.
                }
                else {
                    s.pop();  // If the sum is zero, both asteroids are destroyed.
                    asteroids[i] = 0;
                }
            }
            
            if (asteroids[i] != 0) {
                s.push(asteroids[i]);  // Add the current asteroid to the stack if it's not destroyed.
            }
        }
        
        int n = s.size();  // Get the size of the stack.
        vector<int> ans(n);  // Create a vector to store the remaining asteroids.
        int j = n - 1;  // Initialize an index for the vector.

        while (!s.empty()) {
            ans[j] = s.top();  // Store the remaining asteroids in reverse order.
            s.pop();
            j--;
        }
        
        return ans;  // Return the result as a vector of remaining asteroids.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*-----------------------------------------------------------*/

// 3. Same approach as stack but with vector

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int i = 0; i < asteroids.size(); i++) {
            while (!s.empty() && asteroids[i] < 0 && s.back() > 0) {
                int sum = asteroids[i] + s.back();

                if (sum < 0) {
                    s.pop_back();
                }
                else if (sum > 0) {
                    asteroids[i] = 0;
                }
                else {
                    s.pop_back();
                    asteroids[i] = 0;
                }
            }
            if (asteroids[i] != 0) {
                s.push_back(asteroids[i]);
            }
        }
        
        int n = s.size();
        vector<int> ans(n);
        int j = n - 1;
        while (!s.empty()) {
            ans[j] = s.back();
            s.pop_back();
            j--;
        }
        return ans;
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

