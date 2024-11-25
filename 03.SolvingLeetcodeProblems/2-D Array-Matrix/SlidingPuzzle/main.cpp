//773. Sliding Puzzle

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Step 1: Convert the 2x3 board into a single string for easier manipulation
        string givenStart = "";
        for (int i = 0; i < 2; i++) { // Loop over rows
            for (int j = 0; j < 3; j++) { // Loop over columns
                givenStart += to_string(board[i][j]); // Append each number to the string
            }
        }

        // Step 2: Define the target configuration
        string givenTarget = "123450";

        // Step 3: Set up a queue for BFS and enqueue the initial configuration
        queue<string> que;
        que.push(givenStart);

        // Step 4: Create a map of possible swaps for each index in the string
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};       // From index 0, you can swap with indices 1 and 3
        mp[1] = {0, 2, 4};    // From index 1, you can swap with indices 0, 2, and 4
        mp[2] = {1, 5};       // From index 2, you can swap with indices 1 and 5
        mp[3] = {0, 4};       // From index 3, you can swap with indices 0 and 4
        mp[4] = {1, 3, 5};    // From index 4, you can swap with indices 1, 3, and 5
        mp[5] = {2, 4};       // From index 5, you can swap with indices 2 and 4

        // Step 5: Use a set to track visited states
        unordered_set<string> visited;
        visited.insert(givenStart); // Mark the initial configuration as visited

        // Step 6: Initialize move counter
        int moves = 0;

        // Step 7: Perform BFS
        while (!que.empty()) {
            int n = que.size(); // Get the number of states at the current BFS level

            while (n--) { // Process all states in the current BFS level
                string currentState = que.front(); // Get the current state
                que.pop();

                // Step 8: If the current state matches the target, return the number of moves
                if (currentState == givenTarget) {
                    return moves;
                }

                // Step 9: Find the position of the '0' (empty space) in the current state
                int indexOfZero = currentState.find('0');

                // Step 10: Try all possible swaps for the '0' position
                for (int swapIndex : mp[indexOfZero]) {
                    string newState = currentState;
                    swap(newState[indexOfZero], newState[swapIndex]); // Perform the swap

                    // If this new state hasn't been visited yet, add it to the queue
                    if (visited.find(newState) == visited.end()) {
                        que.push(newState);
                        visited.insert(newState); // Mark the state as visited
                    }
                }
            }
            // Increment the move counter after processing all states at this level
            moves++;
        }

        // If no solution is found, return -1
        return -1;
    }
};

/*Explanation:
BFS Approach:

BFS ensures that we find the shortest path (minimum moves) to reach the target configuration.
Each level of the BFS represents one move.
State Representation:

The puzzle board is converted into a single string to simplify state transitions and comparisons.
The string allows direct manipulation of positions, such as finding the index of '0' and performing swaps.
Swap Map (mp):

The map defines the valid swaps for each index, ensuring only legal moves are attempted.
Visited Set:

Keeps track of visited configurations to avoid revisiting states and entering infinite loops.
Early Exit:

If the target configuration is reached, return the number of moves immediately.
Key Calculation:
For a 
2
×
3
2×3 board:

The board has 6 tiles, including a "0" (empty space).
There are 6!.
6! (factorial of 6) = 720 unique permutations of the tiles.

Complexity Analysis:

Time Complexity: In the worst-case scenario, the BFS must explore all possible permutations of the board, which is 6!.

At each state, we check up to 4 possible swaps (since "0" can move up, down, left, or right depending on its position).
However, since the number of swaps per state is constant, the dominating factor remains 6!

Thus, time complexity = 
𝑂(6!) or O(720).
Space Complexity: The BFS queue and the visited set can each hold up to 6! states in the worst case.
Each state is a string of length 6, so the space required for the queue and visited set is proportional to 
6!×6, but the constant factor (string length) is typically omitted in asymptotic complexity.

Thus, space complexity = 
O(6!) or O(720).
*/