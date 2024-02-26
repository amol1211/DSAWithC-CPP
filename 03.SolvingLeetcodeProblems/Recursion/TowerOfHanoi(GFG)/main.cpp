//Tower Of Hanoi (GFG)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Recursive function to solve the Tower of Hanoi problem
    // N: number of disks
    // from: rod number from which to move the disks
    // to: rod number to which to move the disks
    // aux: auxiliary rod number
    // Returns the total number of moves required to solve the Tower of Hanoi problem
    long long toh(int N, int from, int to, int aux) {
        
        // Base case: If there is only one disk to move, move it from 'from' rod to 'to' rod
        if (N == 1) {
            // Print the move
            cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
            // One move is made, so return 1
            return 1;
        }
        
        // Recursive call: Move N-1 disks from 'from' rod to 'aux' rod using 'to' rod as an auxiliary
        int count = toh(N - 1, from, aux, to);
        
        // Print the move: Move the Nth disk from 'from' rod to 'to' rod
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        // Increment the move count
        count += 1;
        
        // Recursive call: Move N-1 disks from 'aux' rod to 'to' rod using 'from' rod as an auxiliary
        count += toh(N - 1, aux, to, from);
        
        // Return the total move count
        return count;
    }
};

/*Time Complexity: The time complexity of the Tower of Hanoi problem is O(2^N), where N is the number of disks. 
This is because the number of moves required grows exponentially with the number of disks.

Space Complexity: The space complexity of the algorithm is O(N) due to the recursive function calls, where N is the 
number of disks. Each recursive call consumes space on the call stack.
*/