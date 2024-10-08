//Rat in a maze 1 - GFG problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    // Function to check if moving to (x, y) is safe
    bool isSafe(int n, vector<vector<int>>& m, int x, int y, vector<vector<int>> &visited) {
        // Check if (x, y) is within bounds, not visited, and is a valid cell (contains 1)
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1)) {
            return true;
        } 
        else {
            return false;
        } 
    }

    // Recursive function to find paths
    void solve(vector<vector<int>>& m, int n, vector<string> &ans, vector<vector<int>> &visited, string path, int x, int y) {
        // Base case: reached the destination
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(n, m, newx, newy, visited)) {
            path.push_back('D');
            solve(m, n, ans, visited, path, newx, newy);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(n, m, newx, newy, visited)) {
            path.push_back('L');
            solve(m, n, ans, visited, path, newx, newy);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(n, m, newx, newy, visited)) {
            path.push_back('R');
            solve(m, n, ans, visited, path, newx, newy);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isSafe(n, m, newx, newy, visited)) {
            path.push_back('U');
            solve(m, n, ans, visited, path, newx, newy);
            path.pop_back();
        }

        // Unmark the current cell as visited (backtrack)
        visited[x][y] = 0;
    }

public:
    // Function to find paths in the given maze
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;

        // Check if the starting cell is blocked
        if (m[0][0] == 0) {
            return ans;
        }

        // Starting cell coordinates
        int srcx = 0;
        int srcy = 0;

        // Initialize visited vector with the same dimensions as the maze and set all values to 0
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }

        // Path variable to store the current path
        string path = "";

        // Call the recursive function
        solve(m, n, ans, visited, path, srcx, srcy);

        // Sort the paths lexicographically
        sort(ans.begin(), ans.end());

        // Return the result
        return ans;
    }
};

//Time Complexity: O(4^(N^2))
//Space Complexity: O(N^2)

/*------------------------------------------------------------------------------*/

// 2. Bactracking approach

class Solution {
private:
    bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &m, int n) {
        if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] != 1) && (m[newx][newy] == 1)) {
            return true;
        } else {
            return false;
        }
    }

    void solve(int x, int y, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {

        // Base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = true;

        // Down
        if (isSafe(x + 1, y, visited, m, n)) {
            solve(x + 1, y, m, n, ans, visited, path + 'D');
        }

        // Left
        if (isSafe(x, y - 1, visited, m, n)) {
            solve(x, y - 1, m, n, ans, visited, path + 'L');
        }

        // Right
        if (isSafe(x, y + 1, visited, m, n)) {
            solve(x, y + 1, m, n, ans, visited, path + 'R');
        }

        // Up
        if (isSafe(x - 1, y, visited, m, n)) {
            solve(x - 1, y, m, n, ans, visited, path + 'U');
        }

        visited[x][y] = false;  // Resetting the visited status for backtracking
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path = "";

        if (m[0][0] == 0) {
            return ans;
        }

        solve(0, 0, m, n, ans, visited, path);
        return ans;
    }
};

//Time Complexity: O(4^(N^2))
//Space Complexity: O(N^2)