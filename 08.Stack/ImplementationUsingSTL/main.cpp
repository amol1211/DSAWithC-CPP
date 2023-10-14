#include <iostream>
#include <stack>
using namespace std;


int main() {

    //Creating stack
    stack<int> s;

    //Push operation
    s.push(2);
    s.push(3);

    //Pop
    s.pop();

    cout << "Printing top element " << s.top() << '\n';

    if(s.empty()) {
        cout << "Stack is empty " << '\n';
    }
    else {
        cout << "Stack is not empty " << '\n';
    }

    cout << "Size of stack is " << s.size() << '\n';

    return 0;
    
}

