//Disjoint set Union-Find-Rank&PathCompression 

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Declare and initialize a vector to store parent nodes
vector<int> parent;
// Declare and initialize a vector to store ranks of nodes
vector<int> rank;

// Function to find the parent node of a given node
int find (int x) {
    // If the current node is its own parent, return the node
    if (x == parent[x]) 
        return x;

    // Recursively find the parent and update the parent of the current node
    return parent[x] = find(parent[x]);
}

// Function to perform Union operation on two nodes
void Union (int x, int y) {
    // Find the parent nodes of x and y
    int x_parent = find(x);
    int y_parent = find(y);

    // If both nodes have the same parent, they are already in the same set
    if (x_parent == y_parent) 
        return;

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


/*Time Complexity:

The time complexity of the find function is O(log n) on average, where n is the number of elements in the set.
The time complexity of the Union function is O(log n) on average, where n is the number of elements in the set.
Both find and Union operations are called a constant number of times in the worst case.
Therefore, the overall time complexity of both find and Union operations remains O(log n) on average.
Space Complexity:

The space complexity is O(n) to store the parent and rank arrays, where n is the number of elements in the set.*/