#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    //Creation of map
    unordered_map<string, int> M;
    
    //Insertion
    //Type1
    pair<string, int> p = make_pair("amol", 3);
    M.insert(p);

    //Type2
    pair<string, int> p2("shinde", 2);
    M.insert(p2);

    //Type3
    M["great"] = 1;

    M["great"] = 2; //It will update value of great as 2


    //Searching
    cout << M["great"] << endl;

    cout << M.at("amol") << endl;

// cout << M.at("unknownKey") << endl; //error
    
    cout << M["unknownKey"] << endl; //This syntax will create new entry of "unknownKey" and assign 0 if no such key is found.

    //Checking size

    cout << M.size() << endl;
    
    //Checking if perticular key is present or not
    cout << M.count("bro") << endl;
    //count will also create new entry of that key and assign 0 if key is not present otherwise prints count(frequency) of that perticular key.

    //Erasing a key
    M.erase("shinde");
    cout << M.size() << endl;

    //Traversing a map using for loop
    for (auto i: M) {
        cout << i.first << " " << i.second << endl;
    }

    //Traversing a map using iterator
    unordered_map<string, int> :: iterator it = M.begin();

    while (it != M.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    

    return 0;
}

//unordered map has complexity of O(1) also prints in random order
//and map has complexity of o(log(n)) and order is preserved (meaning it prints in the order it was created)