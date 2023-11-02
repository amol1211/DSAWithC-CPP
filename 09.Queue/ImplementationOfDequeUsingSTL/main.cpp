#include <iostream>
#include <queue>
using namespace std;

int main() {

    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << '\n';
    cout << d.back() << '\n';

    d.pop_front();

    cout << d.front() << '\n';
    cout << d.back() << '\n';
    d.pop_back();

    if (d.empty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue is not empty" << '\n';
    }

}