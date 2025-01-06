#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){

    // set creation
    set<int> Set_Example;

    // set members initialization
    Set_Example = {1, 2, 3, 4, 5};

    // set iterator
    set<int>::iterator Set_Iterator = Set_Example.begin();  // Set_Example.end() leads to unpredictable behavior. Which is why for loops
                                                            // stop at != Set_Example.end()
                                                            // Iterator is a pointer

    // number of elements
    int length = Set_Example.size();

    // add elements
    Set_Example.insert(8); // adds at the end

    // remove elements
    Set_Example.erase(2); // removes an element

    // check if element is present: METHOD 1
    bool is_present = Set_Example.contains(3); // 1 if contains and 0 if does not contain
    std::cout << is_present << "\n";

    // check if empty
    bool is_empty = Set_Example.empty();    // 1 if empty and 0 if not empty
    std::cout << is_empty << "\n";

    // access a specific element
    set<int>::iterator Set_Iterator_plustwo = std::next(Set_Iterator, 2); // two positions after first element
    std::cout << *Set_Iterator_plustwo << "\n";

    set<int>::iterator Set_Iterator_minusone = std::prev(Set_Iterator_plustwo, 1); // one position before third element
    std::cout << *Set_Iterator_minusone << "\n";    //dereference

    // check for position of an element
    set<int>::iterator This_Position = Set_Example.find(4); // returns iterator pointing to location of element

    // check if element exists: METHOD 2
    bool is_present_v2 = This_Position != Set_Example.end(); // similar logic to iterative for loop
    std::cout << is_present_v2 << "\n\n";
    
    // Set_Example.clear();     // REMOVE ALL ELEMENTS
    
    // display elements
    // METHOD 1
    for(auto& x: Set_Example){
        std::cout << x << "\n";
    }
    
    std::cout << "\n\n\n\n\n";

    // METHOD 2
    for(Set_Iterator = Set_Example.begin(); Set_Iterator != Set_Example.end(); Set_Iterator++){
        std::cout << *Set_Iterator << "\n";
    }

    return 0;

}