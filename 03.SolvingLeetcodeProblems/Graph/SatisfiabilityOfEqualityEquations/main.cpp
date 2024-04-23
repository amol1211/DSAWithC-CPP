//990. Satisfiability of Equality Equations (GFG)

#include <bits/stdc++.h>
using namespace std;


// Define a class named Solution
class Solution {
public:
    // Declare public member variables
    vector<int> parent; // Store parent nodes
    vector<int> rank; // Store rank of each node
    
    // Function to find the parent node of a given node
    int find(int x) {
        // If the parent of the node is itself, return the node
        if(parent[x] == x)
            return x;
        
        // Recursively find the parent and update the parent of the current node
        return parent[x] = find(parent[x]);
    }
    
    // Function to perform Union operation on two nodes
    void Union(int x, int y) {
        // Find the parent nodes of x and y
        int x_parent = find(x);
        int y_parent = find(y);
 
        // Compare the ranks of the parent nodes
        if(rank[x_parent] > rank[y_parent]) {
            // If rank of x's parent is greater, make y's parent point to x's parent
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            // If rank of y's parent is greater, make x's parent point to y's parent
            parent[x_parent] = y_parent;
        } else {
            // If ranks are equal, make one parent point to the other and increase rank by 1
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }  
    
    // Function to check if a system of equations is possible
    bool equationsPossible(vector<string>& equations) {
        // Resize parent and rank vectors to store 26 characters (a-z)
        parent.resize(26);
        rank.resize(26, 0);

        // Initialize parent vector with each character as its own parent
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        
        // First, perform union of equal characters
        for (string &s : equations) {
            // If it's an equation of the form "a==b", perform union of characters 'a' and 'b'
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        // Check inequalities and validate the system of equations
        for (string& s : equations) {
            // If it's an inequality of the form "a != b"
            if (s[1] == '!') {
                char first = s[0]; // Get the first character
                char second = s[3]; // Get the second character

                // Find the parent nodes of the characters
                int parent_first = find(first - 'a');
                int parent_second = find(second - 'a');

                // If the parent nodes are the same, the system is invalid
                if (parent_first == parent_second)
                    return false;
            }
        }

        // If all inequalities are satisfied, the system is valid
        return true;
    }
}; 

/*Time Complexity:

For the find and Union operations, the time complexity is O(log n) on average, where n is the number of 
elements in the set.
In the equationsPossible function:
The loop to perform union of equal characters iterates through each equation once, which takes O(n) time, 
where n is the number of equations.
The loop to check inequalities also iterates through each equation once, which also takes O(n) time.
Overall, the time complexity of the equationsPossible function is O(n).
Therefore, the overall time complexity is O(n) for the equationsPossible function.

Space Complexity:

The space complexity is O(26) for the parent and rank arrays, as they store information for each character.
Therefore, the overall space complexity is O(26), which can be simplified to O(1).*/
