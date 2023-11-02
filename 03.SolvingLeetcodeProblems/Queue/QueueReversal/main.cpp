//GFG problem
//Queue reversal

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Approach 1 : using stack

class Solution {
    queue<int> rev(queue<int> q) {
        stack<int> s;
        
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        while (!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        return q;
    }
};

//Time complexity of O(N)
//Space complexity of O(N)

/*-------------------------------------------------------------------------*/

//Approach 2 : Using recursion  

class Solution {
public:
    void reverseQueue(queue<int> &q) {
        if (q.empty()) {
            return;
        }

        int front = q.front();
        q.pop();

        reverseQueue(q);

        q.push(front);
    }

    queue<int> rev(queue<int> q) {
        reverseQueue(q); // Call the reverseQueue function to reverse the queue in-place.
        return q;
    }
};

//Time complexity of O(N)
//Space complexity of O(N)