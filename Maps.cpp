#include <iostream>
#include <map>
#include <string>
using namespace std;

// std::map<key, value> NAME
// (i) each key must be unique
// (ii) keys are automatically sorted



int main(){

// map definition
std::map<int, string> Map_Example = {{1, "james"}, {2, "samuel"}, {3, "michael"}}; 
Map_Example[4] = "Kevin";

// iterator
std::map<int, string>::iterator Iter = Map_Example.begin(); // Map_Example.end() leads to unexpected behavior
std::cout << "\nKey: " << Iter->first << "\nValue: " << Iter->second << "\n"; // first: key, second: value

// "value" (second) element can be acessed like so
std::cout << Map_Example[2];

// insert elements like so
Map_Example.insert({8, "hannah"});
// check if a value exists through its key
bool is_contained = Map_Example.contains(3);

// check if empty
bool is_empty = Map_Example.empty();

//size of map
int length = Map_Example.size();
std::cout << "Length is " << length << "\n";
// find element
std::map<int, string>::iterator an_iterator = Map_Example.find(2);      //returns an iterator to key "2"
std::map<int, string>::iterator another_iterator = std::next(Map_Example.begin(), 3); //returns an iterator to the 3rd key (2 positions after the 1st)

// iterate through elements
// METHOD 1:
for(auto& x: Map_Example){
    std::cout << "\nKey: " << x.first << "\nValue: " << x.second << "\n"; 
}

std::cout << "\n\n\n\n";
// METHOD 2:
for(std::map<int, string>::iterator i = Map_Example.begin(); i != Map_Example.end(); i++){
    std::cout << "\nKey: " << i->first << "\nValue: " << i->second << "\n"; 
}
}