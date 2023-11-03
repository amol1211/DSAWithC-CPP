//GFG Problem
//Reverse First K elements of Queue

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> s;
    
    //Step 1 : Pop first K elements from queue push them into stack
    for (int i = 0; i < k; i++) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    //Step 2 : fetch from stack and push them into queue
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    //Step 3 : Fetch first (n - k) elements from stack and push them back into stack
    int t = q.size() - k;
    
    while (t--) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
    return q;
    
}