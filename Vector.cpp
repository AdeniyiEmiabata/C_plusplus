#include <iostream>
#include <vector>

int main(){
// vector definition
std::vector<int> Vector_Example = {1, 2, 6, 8, 45, 23};

// iterator
std::vector<int>::iterator Iter = Vector_Example.begin(); //modifying the vector while iterating can cause invalidate iterators
//add elements
Vector_Example.push_back(11); // adds element at the end of the vector "array"

// NOTE: Iterator is invalid after you .insert(), .erase(), or .push_back()
// So reinitialize
Iter = Vector_Example.begin();
Vector_Example.insert(Iter + 2, 35); // inserts element "35" at the 3rd position. 2 steps from .begin() == first element
// NOTE: Iterator is invalid after you .insert(), .erase(), or .push_back()
// So reinitialize
Iter = Vector_Example.begin();
std::cout << "Third element is " << *(Iter + 2) << "\n";
std::cout << "\n\n\n";
// remove element
Vector_Example.erase(Iter + 1);
// NOTE: Iterator is invalid after you .insert(), .erase(), or .push_back()
// So reinitialize
Iter = Vector_Example.begin();
// Vector_Example.clear(); //deletes whole vector
Vector_Example.pop_back(); // THIS DOES NOT AFFECT ITERATOR to .begin(), only .end()

// accessing elements w/o iterators
std::cout << "Fourth element is "<<Vector_Example[3] << "\n";

std::cout << "\n\n\n";

// iterating through all elements
for(int i = 0; i < Vector_Example.size(); i++){
    std::cout << Vector_Example[i] << "\n";
}

std::cout << "\n\n\n";

for(auto& a: Vector_Example){
    std::cout << a << "\n";
}

std::cout << "\n\n\n";

for(Iter = Vector_Example.begin(); Iter != Vector_Example.end(); Iter++){
    std::cout << *Iter << "\n";
}

return 0;

}